#include <iostream>
#include "DoublyListP.h"

listClass::listClass()
{
	Count = 0;
	Head = new node;
	Head->Data = NULL;
	Head->Prev = NULL;
	Head->Next = NULL;
}

listClass::listClass(const listClass &L)
{
	Count = L.Count;

	if (L.Head->Next == NULL)
	{
		Head = new node;
		Head->Data = NULL;
		Head->Prev = NULL;
		Head->Next = NULL;
	}
	else
	{
		Head = new node;
		Head->Data = L.Head->Data;
		Head->Prev = NULL;
		Head->Next = NULL;

		Nptr Temp1 = Head;
		for (Nptr Temp2 = L.Head->Next; Temp2 != NULL; Temp2 = Temp2->Next)
		{
			Temp1->Next = new node;
			Temp1 = Temp1->Next;
			Temp1->Data = Temp2->Data;
		}
		Temp1->Next = NULL;
	}
}

listClass::~listClass()
{
	while (isEmpty() == false)
	{
		Delete(0);
	}
}

void listClass::Insert(int Position, int Item)
{
	if (Position < 0 || Count < Position)
		return;

	if (Position == 0)
	{
		Nptr newNode = new node;
		newNode->Data = Item;
		newNode->Prev = NULL;
		newNode->Next = Head->Next;

		if (Head->Next != NULL)
			Head->Next->Prev = newNode;

		Head->Next = newNode;
	}
	else
	{
		Nptr targetNode = Head->Next;
		for (int index = 0; index < Position - 1; index++)
		{
			targetNode = targetNode->Next;
		}

		Nptr newNode = new node;
		newNode->Data = Item;
		newNode->Prev = targetNode;
		newNode->Next = targetNode->Next;

		if (targetNode->Next != NULL)
			targetNode->Next->Prev = newNode;

		targetNode->Next = newNode;
	}

	Count++;
}

void listClass::Delete(int Position)
{
	if (Position < 0 || Count <= Position)
		return;

	Nptr targetNode = Head->Next;
	if (Position == 0)
	{
		Head->Next = targetNode->Next;

		if (Head->Next != NULL)
			Head->Next->Prev = NULL;
	}
	else
	{
		Nptr prevNode = targetNode;
		for (int index = 1; index <= Position; index++)
		{
			prevNode = targetNode;
			targetNode = targetNode->Next;
		}

		prevNode->Next = targetNode->Next;

		if (prevNode->Next != NULL)
			prevNode->Next->Prev = prevNode;
	}

	delete (targetNode);
	Count--;
}

void listClass::Retrieve(int Position, int &Item)
{
	if (Position < 0 || Count < Position)
		return;

	Nptr targetNode = Head->Next;
	for (int index = 0; index < Position; index++)
	{
		targetNode = targetNode->Next;
	}

	Item = targetNode->Data;
}

bool listClass::isEmpty()
{
	if (Count < 1)
		return true;
	else
		return false;
}

int listClass::Length()
{
	return Count;
}
