#include "DoublyListP.h"

int main()
{
	listClass list = listClass();		// ������
	listClass list2 = listClass(list);	// ����ִ� ����Ʈ ����

	list.Insert(0, 2);		// �� ó�� (����ִ� ����)
	list.Insert(1, 4);		// �� ��
	list.Insert(0, 1);		// �� ó�� (���� �ִ� ����)
	list.Insert(2, 3);		// �߰� (�� �ڷ� ���� �ִ� ����)
	// ��� list���� ��: 1, 2, 3, 4

	listClass list3 = listClass(list);		// ���� ����ִ� ����Ʈ ����
	// list3���� ��: 1, 2, 3, 4
	
	int data = 0;
	list.Retrieve(0, data);		// �� ó�� data: 1
	list.Retrieve(1, data);		// �߰� �� data: 2
	list.Retrieve(3, data);		// �� ��   data: 4

	list.Delete(0);		// �� ó�� ����
	list.Delete(1);		// �߰� �� ����
	list.Delete(1);		// �� �� ����
	// ��� list���� ��: 2

	bool isEmpty = false;
	isEmpty = list.isEmpty();		// list: ���� ����ִ� ����Ʈ	isEmpty: False
	isEmpty = list2.isEmpty();		// list2: �� ����Ʈ				isEmpty: True
	isEmpty = list3.isEmpty();		// list3: ���� ����ִ� ����Ʈ	isEmpty: False

	int listLength = 0;
	listLength = list.Length();		// list: { 2 }				listLength: 1
	listLength = list2.Length();	// list2: { }				listLength: 0
	listLength = list3.Length();	// list3: { 1, 2, 3, 4 }	listLength: 4

	return 0;		// �Ҹ��� ȣ��
}