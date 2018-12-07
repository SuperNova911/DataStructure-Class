public class Main
{
	public static void main(String[] args)
	{
		DoublylinkedList list = new DoublylinkedList();				// 생성자
		DoublylinkedList list2 = new DoublylinkedList(list);		// 비어있는 리스트 복사
		// list: { }, list2: { }

		list.Insert(0, 2);			// 맨 처음 (비어있는 상태)
		list.Insert(1, 4);			// 맨 끝
		list.Insert(0, 1);			// 맨 처음 (값이 있는 상태)
		list.Insert(2, 3);			// 중간 (앞 뒤로 값이 있는 상태)
		// list: { 1, 2, 3, 4 }
		
		DoublylinkedList list3 = new DoublylinkedList(list);		// 값이 들어있는 리스트 복사
		// list3: { 1, 2, 3, 4 }

		int data = 0;
		data = list.Retrieve(0);		// 맨 처음 data: 1
		data = list.Retrieve(1);		// 중간 값 data: 2
		data = list.Retrieve(3);		// 맨 끝   data: 4

		list.Delete(0);			// 맨 처음 삭제
		list.Delete(1);			// 중간 값 삭제
		list.Delete(1);			// 맨 끝 삭제
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
