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

	string input1 = "( 1 + ( ( 5 + 8 ) * ( 10 + 7.5 ) ) )";
	string input2 = "( ( 2 + pow ( 5.0 , 3.0 ) + log ( 7.0 ) ) / 3.0 )";
	string input3 = "( ( 2 + sqrt ( 10.0 ) ) * ( log ( 2.0 ) + 5 ) )";
	string input4 = "( 5 + 6";
	string input5 = "pow ( 6 7 ) + log ( 5 )";
	string input6 = "( 4 + 2 ) * 10 )";

	vector<string> elements = Split(input6, ' ');

	// Check syntax error
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
		if (elements[index] == "(")
		{
			operatorStack.Push(elements[index]);
		}
		else if (elements[index] == ")")
		{
			operatorStack.GetTop(expression);

			while (expression != "(")
			{
				x = 0;
				y = 0;
				operatorStack.Pop();

				operandStack.GetTop(y);
				operandStack.Pop();
				operandStack.GetTop(x);
				operandStack.Pop();

				operandStack.Push(Calculate(expression, x, y));
				operatorStack.GetTop(expression);
			}
			operatorStack.Pop();

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
		else if (IsDouble(elements[index]))
		{
			operandStack.Push(stod(elements[index]));
		}
		else if (IsExpression(elements[index]))
		{
			operatorStack.Push(elements[index]);
		}
		else if (IsSpecialExpression(elements[index]))
		{
			operatorStack.Push(elements[index]);
			waitSpecialExpression++;
		}
		else if (elements[index] == ",")
		{
			continue;
		}
		else
		{
			cout << "syntax error" << endl;
			return 0;
		}
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

vector<string> Split(const string &s, char delim) 
{
	vector<string> elements;
	Split(s, delim, back_inserter(elements));
	return elements;
}

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

bool IsExpression(const string &s)
{
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

bool IsSpecialExpression(const string &s)
{
	return (s == "pow" || s == "log" || s == "sqrt");
}

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