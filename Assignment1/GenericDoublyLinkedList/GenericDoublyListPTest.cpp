#include "GenericDoublyListP.h"

using namespace std;

int main()
{
	// #### listClass<int> ####
	listClass<int> list_int = listClass<int>();					// ������
	listClass<int> list_int2 = listClass<int>(list_int);		// ����ִ� ����Ʈ ����
																// list_int = { }, list_int2 = { }

	list_int.Insert(0, 2);			// �� ó�� (����ִ� ����)
	list_int.Insert(1, 4);			// �� ��
	list_int.Insert(0, 1);			// �� ó�� (���� �ִ� ����)
	list_int.Insert(2, 3);			// �߰� (�� �ڷ� ���� �ִ� ����)
									// list_int = { 1, 2, 3, 4 }

	listClass<int> list_int3 = listClass<int>(list_int);		// ���� ����ִ� ����Ʈ ����
																// list_int3 = { 1, 2, 3, 4 }

	int data_int = 0;
	list_int.Retrieve(0, data_int);		// �� ó�� data_int: 1
	list_int.Retrieve(1, data_int);		// �߰� �� data_int: 2
	list_int.Retrieve(3, data_int);		// �� ��   data_int: 4

	list_int.Delete(0);		// �� ó�� ����
	list_int.Delete(1);		// �߰� �� ����
	list_int.Delete(1);		// �� �� ����
							// list_int = { 2 }

	bool isEmpty = false;
	isEmpty = list_int.isEmpty();		// list_int: { 2 }				isEmpty: False
	isEmpty = list_int2.isEmpty();		// list_int2: { }				isEmpty: True
	isEmpty = list_int3.isEmpty();		// list_int3: { 1, 2, 3, 4 }	isEmpty: False

	int listLength = 0;
	listLength = list_int.Length();		// list_int: { 2 }				listLength: 1
	listLength = list_int2.Length();	// list_int2: { }				listLength: 0
	listLength = list_int3.Length();	// list_int3: { 1, 2, 3, 4 }	listLength: 4



	// #### listClass<double> ####
	listClass<double> list_double = listClass<double>();					// ������
	listClass<double> list_double2 = listClass<double>(list_double);		// ����ִ� ����Ʈ ����
																			// list_double = { }, list_double2 = { }

	list_double.Insert(0, 5.0);			// �� ó�� (����ִ� ����)
	list_double.Insert(1, 10.0);		// �� ��
	list_double.Insert(0, 2.5);			// �� ó�� (���� �ִ� ����)
	list_double.Insert(2, 7.5);			// �߰� (�� �ڷ� ���� �ִ� ����)
										// list_double = { 2.5, 5.0, 7.5, 10.0 }

	listClass<double> list_double3 = listClass<double>(list_double);		// ���� ����ִ� ����Ʈ ����
																			// list_double3 = { 2.5, 5.0, 7.5, 10.0 }

	double data_double = 0.0;
	list_double.Retrieve(0, data_double);		// �� ó�� data_double: 2.5
	list_double.Retrieve(1, data_double);		// �߰� �� data_double: 5.0
	list_double.Retrieve(3, data_double);		// �� ��   data_double: 10.0

	list_double.Delete(0);		// �� ó�� ����
	list_double.Delete(1);		// �߰� �� ����
	list_double.Delete(1);		// �� �� ����
								// list_double = { 5.0 }

	isEmpty = false;
	isEmpty = list_double.isEmpty();		// list_double: { 5.0 }						isEmpty: False
	isEmpty = list_double2.isEmpty();		// list_double2: { }						isEmpty: True
	isEmpty = list_double3.isEmpty();		// list_double3: { 2.5, 5.0, 7.5, 10.0 }	isEmpty: False

	listLength = 0;
	listLength = list_double.Length();		// list_double: { 5.0 }						listLength: 1
	listLength = list_double2.Length();		// list_double2: { }						listLength: 0
	listLength = list_double3.Length();		// list_double3: { 2.5, 5.0, 7.5, 10.0 }	listLength: 4



	// #### listClass<string> ####
	listClass<string> list_string = listClass<string>();					// ������
	listClass<string> list_string2 = listClass<string>(list_string);		// ����ִ� ����Ʈ ����
																			// list_string = { }, list_string2 = { }

	list_string.Insert(0, "Bb");		// �� ó�� (����ִ� ����)
	list_string.Insert(1, "Dd");		// �� ��
	list_string.Insert(0, "Aa");		// �� ó�� (���� �ִ� ����)
	list_string.Insert(2, "Cc");		// �߰� (�� �ڷ� ���� �ִ� ����)
										// list_string = { Aa, Bb, Cc, Dd }

	listClass<string> list_string3 = listClass<string>(list_string);		// ���� ����ִ� ����Ʈ ����
																			// list_string3 = { Aa, Bb, Cc, Dd }

	string data_string = "";
	list_string.Retrieve(0, data_string);		// �� ó�� data_string: Aa
	list_string.Retrieve(1, data_string);		// �߰� �� data_string: Bb
	list_string.Retrieve(3, data_string);		// �� ��   data_string: Dd

	list_string.Delete(0);		// �� ó�� ����
	list_string.Delete(1);		// �߰� �� ����
	list_string.Delete(1);		// �� �� ����
								// list_string = { Bb }

	isEmpty = false;
	isEmpty = list_string.isEmpty();		// list_string: { Bb }					isEmpty: False
	isEmpty = list_string2.isEmpty();		// list_string2: { }					isEmpty: True
	isEmpty = list_string3.isEmpty();		// list_string3: { Aa, Bb, Cc, Dd }		isEmpty: False

	listLength = 0;
	listLength = list_string.Length();		// list_string: { Bb }					listLength: 1
	listLength = list_string2.Length();		// list_string2: { }					listLength: 0
	listLength = list_string3.Length();		// list_string3: { Aa, Bb, Cc, Dd }		listLength: 4

	return 0;
}