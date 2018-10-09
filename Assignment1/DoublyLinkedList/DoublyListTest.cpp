#include "DoublyListP.h"

int main()
{
	listClass list = listClass();		// 생성자
	listClass list2 = listClass(list);	// 비어있는 리스트 복사

	list.Insert(0, 2);		// 맨 처음 (비어있는 상태)
	list.Insert(1, 4);		// 맨 끝
	list.Insert(0, 1);		// 맨 처음 (값이 있는 상태)
	list.Insert(2, 3);		// 중간 (앞 뒤로 값이 있는 상태)
	// 결과 list안의 값: 1, 2, 3, 4

	listClass list3 = listClass(list);		// 값이 들어있는 리스트 복사
	// list3안의 값: 1, 2, 3, 4
	
	int data = 0;
	list.Retrieve(0, data);		// 맨 처음 data: 1
	list.Retrieve(1, data);		// 중간 값 data: 2
	list.Retrieve(3, data);		// 맨 끝   data: 4

	list.Delete(0);		// 맨 처음 삭제
	list.Delete(1);		// 중간 값 삭제
	list.Delete(1);		// 맨 끝 삭제
	// 결과 list안의 값: 2

	bool isEmpty = false;
	isEmpty = list.isEmpty();		// list: 값이 들어있는 리스트	isEmpty: False
	isEmpty = list2.isEmpty();		// list2: 빈 리스트				isEmpty: True
	isEmpty = list3.isEmpty();		// list3: 값이 들어있는 리스트	isEmpty: False

	int listLength = 0;
	listLength = list.Length();		// list: { 2 }				listLength: 1
	listLength = list2.Length();	// list2: { }				listLength: 0
	listLength = list3.Length();	// list3: { 1, 2, 3, 4 }	listLength: 4

	return 0;		// 소멸자 호출
}