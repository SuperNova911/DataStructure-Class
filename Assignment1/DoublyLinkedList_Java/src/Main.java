public class Main
{
	public static void main(String[] args)
	{
		DoublylinkedList list = new DoublylinkedList();				// ������
		DoublylinkedList list2 = new DoublylinkedList(list);		// ����ִ� ����Ʈ ����
		// list = { }, list2 = { }

		list.Insert(0, 2);			// �� ó�� (����ִ� ����)
		list.Insert(1, 4);			// �� ��
		list.Insert(0, 1);			// �� ó�� (���� �ִ� ����)
		list.Insert(2, 3);			// �߰� (�� �ڷ� ���� �ִ� ����)
		// list = { 1, 2, 3, 4 }
		
		DoublylinkedList list3 = new DoublylinkedList(list);		// ���� ����ִ� ����Ʈ ����
		// list3 = { 1, 2, 3, 4 }

		int data = 0;
		data = list.Retrieve(0);		// �� ó�� data: 1
		data = list.Retrieve(1);		// �߰� �� data: 2
		data = list.Retrieve(3);		// �� ��   data: 4

		list.Delete(0);			// �� ó�� ����
		list.Delete(1);			// �߰� �� ����
		list.Delete(1);			// �� �� ����
		// list = { 2 }
		
		boolean isEmpty = false;
		isEmpty = list.IsEmpty();		// list: { 2 }				isEmpty: False
		isEmpty = list2.IsEmpty();		// list2: { }				isEmpty: True
		isEmpty = list3.IsEmpty();		// list3: { 1, 2, 3, 4 }	isEmpty: False
		
		int listLength = 0;
		listLength = list.Length();		// list: { 2 }				listLength: 1
		listLength = list2.Length();	// list2: { }				listLength: 0
		listLength = list3.Length();	// list3: { 1, 2, 3, 4 }	listLength: 4
		
		return;
	}

}
