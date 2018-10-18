#include "GenericStackDL.h"

using namespace std;

int main()
{
	// #### StackClass<int> ####
	StackClass<int> stack_int = StackClass<int>();				// 생성자
	StackClass<int> stack_int2 = StackClass<int>(stack_int);	// 비어있는 스택 복사
	// stack_int: { }, stack_int2: { }

	stack_int.Push(1);
	stack_int.Push(2);
	stack_int.Push(3);
	stack_int.Push(4);
	// stack_int: { 4, 3, 2, 1 }

	StackClass<int> stack_int3 = StackClass<int>(stack_int);	// 값이 들어있는 스택 복사
	// stack_int3: { 4, 3, 2, 1 }

	int data_int = 0;
	stack_int.GetTop(data_int);		// data_int: 4
	stack_int.Pop();				// Pop
	stack_int.GetTop(data_int);		// data_int: 3
	stack_int.Pop();				// Pop
	stack_int.GetTop(data_int);		// data_int: 2
	stack_int.Pop();				// Pop
	// stack_int: { 1 }

	bool isEmpty = false;
	isEmpty = stack_int.IsEmpty();		// stack_int: { 1 }				isEmpty: False
	isEmpty = stack_int2.IsEmpty();		// stack_int2: { }				isEmpty: True
	isEmpty = stack_int3.IsEmpty();		// stack_int3: { 4, 3, 2, 1 }	isEmpty: False

	int stackSize = 0;
	stackSize = stack_int.GetSize();	// stack_int: { 1 }				stackSize: 1;
	stackSize = stack_int2.GetSize();	// stack_int2: { }				stackSize: 0;
	stackSize = stack_int3.GetSize();	// stack_int3: { 4, 3, 2, 1 }	stackSize: 4;



	// #### StackClass<double> ####
	StackClass<double> stack_double = StackClass<double>();					// 생성자
	StackClass<double> stack_double2 = StackClass<double>(stack_double);	// 비어있는 스택 복사
	// stack_double: { }, stack_double2: { }

	stack_double.Push(2.5);
	stack_double.Push(5.0);
	stack_double.Push(7.5);
	stack_double.Push(10.0);
	// stack_double: { 10.0, 7.5, 5.0, 2.5 }

	StackClass<double> stack_double3 = StackClass<double>(stack_double);	// 값이 들어있는 스택 복사
	// stack_double3: { 10.0, 7.5, 5.0, 2.5 }

	double data_double = 0.0;
	stack_double.GetTop(data_double);		// data_double: 10.0
	stack_double.Pop();						// Pop
	stack_double.GetTop(data_double);		// data_double: 7.5
	stack_double.Pop();						// Pop
	stack_double.GetTop(data_double);		// data_double: 5.0
	stack_double.Pop();						// Pop
	// stack_double: { 2.5 }

	isEmpty = false;
	isEmpty = stack_double.IsEmpty();		// stack_double: { 2.5 }					isEmpty: False
	isEmpty = stack_double2.IsEmpty();		// stack_double2: { }						isEmpty: True
	isEmpty = stack_double3.IsEmpty();		// stack_double3: { 10.0, 7.5, 5.0, 2.5 }	isEmpty: False

	stackSize = 0;
	stackSize = stack_double.GetSize();		// stack_double: { 2.5 }					stackSize: 1;
	stackSize = stack_double2.GetSize();	// stack_double2: { }						stackSize: 0;
	stackSize = stack_double3.GetSize();	// stack_double3: { 10.0, 7.5, 5.0, 2.5 }	stackSize: 4;



	// #### StackClass<string> ####
	StackClass<string> stack_string = StackClass<string>();					// 생성자
	StackClass<string> stack_string2 = StackClass<string>(stack_string);	// 비어있는 스택 복사
	// stack_string: { }, stack_string2: { }

	stack_string.Push("Aa");
	stack_string.Push("Bb");
	stack_string.Push("Cc");
	stack_string.Push("Dd");
	// stack_string: { Dd, Cc, Bb, Aa }

	StackClass<string> stack_string3 = StackClass<string>(stack_string);	// 값이 들어있는 스택 복사
	// stack_string3: { Dd, Cc, Bb, Aa }

	string data_string = "";
	stack_string.GetTop(data_string);		// data_string: Dd
	stack_string.Pop();						// Pop
	stack_string.GetTop(data_string);		// data_string: Cc
	stack_string.Pop();						// Pop
	stack_string.GetTop(data_string);		// data_string: Bb
	stack_string.Pop();						// Pop
	// stack_string: { Aa }

	isEmpty = false;
	isEmpty = stack_string.IsEmpty();		// stack_string: { Aa }					isEmpty: False
	isEmpty = stack_string2.IsEmpty();		// stack_string2: { }					isEmpty: True
	isEmpty = stack_string3.IsEmpty();		// stack_string3: { Dd, Cc, Bb, Aa }	isEmpty: False

	stackSize = 0;
	stackSize = stack_string.GetSize();		// stack_string: { Aa }					stackSize: 1;
	stackSize = stack_string2.GetSize();	// stack_string2: { }					stackSize: 0;
	stackSize = stack_string3.GetSize();	// stack_string3: { Dd, Cc, Bb, Aa }	stackSize: 4;

	return 0;
}