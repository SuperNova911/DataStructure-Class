#pragma once
#include "GenericDoublyListP.h"
#include <iostream>

template<class T>
class StackClass
{
public:
	StackClass();
	StackClass(const StackClass& S);
	~StackClass();
	void Push(T item);
	void Pop();
	void GetTop(T &item);
	bool IsEmpty();
	int GetSize();

private:
	listClass<T> *List;
};

template<class T>
inline StackClass<T>::StackClass()
{
	List = new listClass<T>();
}

template<class T>
inline StackClass<T>::StackClass(const StackClass & S)
{
	List = new listClass<T>(*S.List);
}

template<class T>
inline StackClass<T>::~StackClass()
{
	while (IsEmpty() == false)
	{
		Pop();
	}
	delete List;
}

template<class T>
inline void StackClass<T>::Push(T item)
{
	List->Insert(0, item);
}

template<class T>
inline void StackClass<T>::Pop()
{
	List->Delete(0);
}

template<class T>
inline void StackClass<T>::GetTop(T & item)
{
	List->Retrieve(0, item);
}

template<class T>
inline bool StackClass<T>::IsEmpty()
{
	return List->isEmpty();
}

template<class T>
inline int StackClass<T>::GetSize()
{
	return List->Length();
}
