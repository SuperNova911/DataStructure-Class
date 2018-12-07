#include "BST.h"

void SuccessorCopy(Nptr &T, dataType &nodeData)
{
	if (T->LChild == NULL)
	{
		nodeData.Key = T->Data.Key;
		Nptr temp = T;
		T = T->RChild;
		delete temp;
	}
	else
	{
		SuccessorCopy(T->LChild, nodeData);
	}
}

Nptr Search(Nptr T, const char *key)
{
	if (T == NULL)
	{
		printf("No such node\n");
		return NULL;
	}
	else if (T->Data.Key == key)
		return T;
	else if (T->Data.Key > key)
		return Search(T->LChild, key);
	else
		return Search(T->RChild, key);
}

Nptr Insert(Nptr T, const char *key)
{
	if (T == NULL)
	{
		T = new node;
		T->Data.Key = key;
		T->Data.count = 1;
		T->LChild = NULL;
		T->RChild = NULL;
	}
	else if (T->Data.Key > key)
	{
		T->LChild = Insert(T->LChild, key);
	}
	else
	{
		T->RChild = Insert(T->RChild, key);
	}

	return T;
}

void Delete(Nptr &T, const char *key)
{
	if (T == NULL)
	{
		printf("No record with such key\n");
	}
	else if (T->Data.Key > key)
	{
		Delete(T->LChild, key);
	}
	else if (T->Data.Key < key)
	{
		Delete(T->RChild, key);
	}
	else if (T->Data.Key == key)
	{
		if (T->LChild == NULL && T->RChild == NULL)
		{
			Nptr temp = T;
			T = NULL;
			delete temp;
		}
		else if (T->LChild == NULL)
		{
			Nptr temp = T;
			T = T->RChild;
			delete temp;
		}
		else if (T->RChild == NULL)
		{
			Nptr temp = T;
			T = T->LChild;
			delete temp;
		}
		else
		{
			SuccessorCopy(T->RChild, T->Data);
		}
	}
}

void Update(Nptr &T, const char *key)
{
	if (T == NULL)
	{
		T = new node;
		T->Data.Key = key;
		T->Data.count = 1;
		T->LChild = NULL;
		T->RChild = NULL;
	}
	else if (T->Data.Key > key)
	{
		Update(T->LChild, key);
	}
	else if (T->Data.Key < key)
	{
		Update(T->RChild, key);
	}
	else
	{
		T->Data.count++;
	}
}