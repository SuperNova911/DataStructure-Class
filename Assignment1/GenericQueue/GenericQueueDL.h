#pragma once
#include "GenericDoublyListP.h"
#include <iostream>

template<class T>
class QueueClass
{
public:
	QueueClass();
	QueueClass(const QueueClass& Q);
	~QueueClass();
	void Add(T item);
	void Remove();
	void GetFront(T &item);
	bool IsEmpty();
	int GetSize();

private:
	listClass<T> *List;
};

template<class T>
inline QueueClass<T>::QueueClass()
{
	List = new listClass<T>();
}

template<class T>
inline QueueClass<T>::QueueClass(const QueueClass & Q)
{
	List = new listClass<T>(*Q.List);
}

template<class T>
inline QueueClass<T>::~QueueClass()
{
	while (IsEmpty() == false)
	{
		Remove();
	}
	delete List;
}

template<class T>
inline void QueueClass<T>::Add(T item)
{
	List->Insert(List->Length(), item);
}

template<class T>
inline void QueueClass<T>::Remove()
{
	List->Delete(0);
}

template<class T>
inline void QueueClass<T>::GetFront(T & item)
{
	List->Retrieve(0, item);
}

template<class T>
inline bool QueueClass<T>::IsEmpty()
{
	return List->isEmpty();
}

template<class T>
inline int QueueClass<T>::GetSize()
{
	return List->Length();
}
