#pragma once

#include <iostream> 

template<class T>
struct Node
{
	T Data;
	Node<T> *Prev, *Next;
};

template<class T>
class listClass
{
public:
	listClass();
	listClass(const listClass &L);
	~listClass();
	void Insert(int Position, T Item);
	void Delete(int Position);
	void Retrieve(int Position, T &Item);
	bool isEmpty();
	int Length();

private:
	int Count;
	Node<T> *Head;
};

template<class T>
inline listClass<T>::listClass()
{
	Count = 0;
	Head = new Node<T>;
	//Head->Data = NULL;
	Head->Prev = NULL;
	Head->Next = NULL;
}

template<class T>
inline listClass<T>::listClass(const listClass & L)
{
	Count = 0;
	Head = new Node<T>;
	//Head->Data = NULL;
	Head->Prev = NULL;
	Head->Next = NULL;

	Node<T> *targetNode = L.Head->Next;
	for (int index = 0; targetNode != NULL; index++)
	{
		Insert(index, targetNode->Data);
		targetNode = targetNode->Next;
	}
}

template<class T>
inline listClass<T>::~listClass()
{
	while (isEmpty() == false)
	{
		Delete(0);
	}
}

template<class T>
inline void listClass<T>::Insert(int Position, T Item)
{
	if (Position < 0 || Count < Position)
		return;

	if (Position == 0)
	{
		Node<T> *newNode = new Node<T>;
		newNode->Data = Item;
		newNode->Prev = NULL;
		newNode->Next = Head->Next;

		if (Head->Next != NULL)
			Head->Next->Prev = newNode;

		Head->Next = newNode;
	}
	else
	{
		Node<T> *targetNode = Head->Next;
		for (int index = 0; index < Position - 1; index++)
		{
			targetNode = targetNode->Next;
		}

		Node<T> *newNode = new Node<T>;
		newNode->Data = Item;
		newNode->Prev = targetNode;
		newNode->Next = targetNode->Next;

		if (targetNode->Next != NULL)
			targetNode->Next->Prev = newNode;

		targetNode->Next = newNode;
	}

	Count++;
}

template<class T>
inline void listClass<T>::Delete(int Position)
{
	if (Position < 0 || Count <= Position)
		return;

	Node<T> *targetNode = Head->Next;
	if (Position == 0)
	{
		Head->Next = targetNode->Next;

		if (Head->Next != NULL)
			Head->Next->Prev = NULL;
	}
	else
	{
		Node<T> *prevNode = targetNode;
		for (int index = 1; index <= Position; index++)
		{
			prevNode = targetNode;
			targetNode = targetNode->Next;
		}

		prevNode->Next = targetNode->Next;

		if (targetNode->Next != NULL)
			targetNode->Next->Prev = prevNode;
	}

	delete(targetNode);
	Count--;
}

template<class T>
inline void listClass<T>::Retrieve(int Position, T & Item)
{
	if (Position < 0 || Count < Position)
		return;

	Node<T> *targetNode = Head->Next;
	for (int index = 0; index < Position; index++)
	{
		targetNode = targetNode->Next;
	}

	Item = targetNode->Data;
}

template<class T>
inline bool listClass<T>::isEmpty()
{
	if (Count < 1)
		return true;
	else
		return false;
}

template<class T>
inline int listClass<T>::Length()
{
	return Count;
}
