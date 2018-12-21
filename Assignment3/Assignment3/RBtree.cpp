#include "RBtree.h"

void Rotate(Nptr top, bool toLeft)
{
	Nptr parent = top->Parent;
	Nptr mid;
	treeRecord temp;
	if (toLeft)
	{
		temp = *top->RChild;
		mid = &temp;
		
		parent->LChild = top;
		parent->RChild = mid;
		top->RChild = NULL;

		mid->Parent = parent;
	}
	else
	{
		temp = *top->LChild;
		mid = &temp;

		parent->LChild = mid;
		parent->RChild = top;
		top->LChild = NULL;

		mid->Parent = parent;
	}

	if (parent->Parent != NULL)
	{
		if (parent->Parent->key > mid->key)
		{
			parent->Parent->LChild = mid;
		}
		else
		{
			parent->Parent->RChild = mid;
		}

		mid->Parent = parent;
	}
}

void Insert(Nptr node, int key)
{
	if (node == NULL)
	{
		node = new treeRecord;
		node->key = key;
		node->LChild = NULL;
		node->RChild = NULL;
		node->color = BLACK;
		return;
	}

	if (node->LChild != NULL && node->RChild != NULL &&
		node->LChild->color == node->RChild->color == RED)
	{
		node->LChild->color = node->RChild->color = BLACK;
	}

	if (node->key > key)
	{
		if (node->LChild == NULL)
		{
			node->LChild = new treeRecord;
			node->LChild->key = key;
			node->LChild->LChild = NULL;
			node->LChild->RChild = NULL;
			node->LChild->Parent = node;
			node->LChild->color = RED;
		}
		else
		{
			Insert(node->LChild, key);
		}

		if (node->color == node->LChild->color == RED)
		{
			Rotate(node, false);
		}
	}
	else if (node->key < key)
	{
		if (node->RChild == NULL)
		{
			node->RChild = new treeRecord;
			node->RChild->key = key;
			node->RChild->LChild = NULL;
			node->RChild->RChild = NULL;
			node->RChild->Parent = node;
			node->RChild->color = RED;
		}
		else
		{
			Insert(node->RChild, key);
		}

		if (node->color == node->RChild->color == RED)
		{
			Rotate(node, true);
		}
	}
	else
	{
		cout << "Key is already exist" << endl;
	}
}

void Delete(Nptr node, int key)
{

}

bool RBVertify(Nptr node)
{
	return false;
}

void RBPrettyPrint(const string & prefix, Nptr node, bool isLeft)
{
	if (node != NULL)
	{
		cout << prefix.c_str();

		if (node->color == RED)
			cout << (isLeft ? " " : "      ");
		else
			cout << (isLeft ? "戍式式" : "戌式式");

		cout << node->key;

		if (node->color == RED)
			cout << "*";
		cout << endl;

		RBPrettyPrint(prefix + (isLeft ? " 弛  " : "  "), node->LChild, true);
		RBPrettyPrint(prefix + (isLeft ? " 弛  " : "  "), node->RChild, false);
	}
}
