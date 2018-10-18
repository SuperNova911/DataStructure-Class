#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include "GenericStackDL.h"

using namespace std;

vector<string> Split(const string &s, char delim);
bool IsDouble(const string &s);
bool IsExpression(const string &s);
bool IsSpecialExpression(const string &s);
double Calculate(const string &s, double x, double y);

int main()
{
	StackClass<double> operandStack = StackClass<double>();
	StackClass<string> operatorStack = StackClass<string>();

	// 입력
	string input1 = "( 1 + ( ( 5 + 8 ) * ( 10 + 7.5 ) ) )";
	string input2 = "( ( 2 + pow ( 5.0 , 3.0 ) + log ( 7.0 ) ) / 3.0 )";
	string input3 = "( ( 2 + sqrt ( 10.0 ) ) * ( log ( 2.0 ) + 5 ) )";
	string input4 = "( 5 + 6";
	string input5 = "pow ( 6 7 ) + log ( 5 )";
	string input6 = "( 4 + 2 ) * 10 )";

	// 입력 식 고르기
	cout << "식: " << input1 << endl;
	vector<string> elements = Split(input1, ' ');

	// 괄호 매칭 검사, 연속된 피연산자 검사
	int bracket = 0;
	for (unsigned int index = 0; index < elements.size(); index++)
	{
		if (elements[index] == "(")
			bracket++;
		else if (elements[index] == ")")
			bracket--;

		if (index < elements.size() - 1 && IsDouble(elements[index]) && IsDouble(elements[index + 1]))
		{
			cout << "syntax error" << endl;
			return 0;
		}
	}
	if (bracket != 0)
	{
		cout << "syntax error" << endl;
		return 0;
	}

	int waitSpecialExpression = 0;
	double x, y;
	string expression;
	for (unsigned int index = 0; index < elements.size(); index++)
	{
		// 연산자 스택에 추가
		if (elements[index] == "(")
		{
			operatorStack.Push(elements[index]);
		}
		// 스택에서 연산자와 피연산자를 불러와 연산 수행
		else if (elements[index] == ")")
		{
			operatorStack.GetTop(expression);
			operatorStack.Pop();

			// 닫는 괄호가 나오기 전까지 연산자와 피연산자를 꺼내며 연산 수행후 피연산자 스택에 결과값을 집어넣음
			while (expression != "(")
			{
				x = 0;
				y = 0;

				operandStack.GetTop(y);
				operandStack.Pop();
				operandStack.GetTop(x);
				operandStack.Pop();

				operandStack.Push(Calculate(expression, x, y));
				operatorStack.GetTop(expression);
				operatorStack.Pop();
			}

			// pow, log, sqrt연산이 기다리고 있으면 실행
			if (waitSpecialExpression > 0)
			{
				operatorStack.GetTop(expression);

				if (IsSpecialExpression(expression))
				{
					operatorStack.Pop();

					if (expression == "pow")
					{
						operandStack.GetTop(y);
						operandStack.Pop();
						operandStack.GetTop(x);
						operandStack.Pop();
					}
					else
					{
						operandStack.GetTop(x);
						operandStack.Pop();
						y = 0;
					}

					operandStack.Push(Calculate(expression, x, y));
					waitSpecialExpression--;
				}
				else
				{
					cout << "syntax error" << endl;
					return 0;
				}
			}
		}
		// Double로 변환 가능한지 검사
		else if (IsDouble(elements[index]))
		{
			operandStack.Push(stod(elements[index]));
		}
		// 연산자인지 검사
		else if (IsExpression(elements[index]))
		{
			operatorStack.Push(elements[index]);
		}
		// pow, log, sqrt인지 검사
		else if (IsSpecialExpression(elements[index]))
		{
			operatorStack.Push(elements[index]);
			waitSpecialExpression++;
		}
		// 구분자 ','인지 검사
		else if (elements[index] == ",")
		{
			continue;
		}
		// 잘못된 요소
		else
		{
			cout << "syntax error" << endl;
			return 0;
		}
	}

	// 피연산자 스택에 결과값 하나만 남아있어야 정상적인 식
	if (operandStack.GetSize() == 1 && operatorStack.GetSize() == 0)
	{
		double result;
		operandStack.GetTop(result);
		cout << "계산결과: " << result << endl;
	}
	else
	{
		cout << "syntax error" << endl;
	}

	return 0;
}

template<typename Out>
void Split(const string &s, char delim, Out result)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

// 문자열 나누기
vector<string> Split(const string &s, char delim)
{
	vector<string> elements;
	Split(s, delim, back_inserter(elements));
	return elements;
}

// Double 타입으로 변환 가능한지 검사
bool IsDouble(const string &s)
{
	try
	{
		stod(s);
		return true;
	}
	catch (invalid_argument)
	{
		return false;
	}
	catch (out_of_range)
	{
		return false;
	}
}

// 연산자인지 검사
bool IsExpression(const string &s)
{
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

// pow, log, sqrt인지 검사
bool IsSpecialExpression(const string &s)
{
	return (s == "pow" || s == "log" || s == "sqrt");
}

// 연산자와 피연산자를 받아 연산후 결과값 반환
double Calculate(const string &s, double x, double y)
{
	if (s == "+")
		return x + y;
	else if (s == "-")
		return x - y;
	else if (s == "*")
		return x * y;
	else if (s == "/")
		return x / y;
	else if (s == "pow")
		return pow(x, y);
	else if (s == "log")
		return log(x);
	else if (s == "sqrt")
		return sqrt(x);
	else
	{
		cout << "syntax error" << endl;
		return 0;
	}
}