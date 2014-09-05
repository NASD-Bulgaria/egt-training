#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <new>
#include "TwoLinked.h"
using namespace std;

template<typename NODETYPE>
class List
{
public:
	List();
	List(const List<NODETYPE> &);
	~List();

	void insertAtFront(const NODETYPE &);
	void insertAtBack(const NODETYPE &);
	bool removeFromFront(NODETYPE &);
	bool removeFromBack(NODETYPE &);
	bool isEmpty() const;
	void print() const;
protected:
	TwoLinked<NODETYPE> *firstPtr;
	TwoLinked<NODETYPE> *lastPtr;

	TwoLinked<NODETYPE> *getNewNode(const NODETYPE &);
};

template<typename NODETYPE>
List<NODETYPE>::List()
{
	firstPtr = lastPtr = 0;
}
template<typename NODETYPE>
List<NODETYPE>::List(const List<NODETYPE> &copy)
{
	firstPtr = lastPtr = 0;

	TwoLinked<NODETYPE> *currentPtr = copy.firstPtr;

	while (currentPtr != 0)
	{
		insertAtBack(currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
}

template<typename NODETYPE>
List<NODETYPE>::~List()
{
	if (!isEmpty())
	{
		cout << "Destroying nodes ...\n";

		TwoLinked<NODETYPE> *currentPtr = firstPtr;
		TwoLinked<NODETYPE> *tempPtr;

		while (currentPtr != 0)
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}
	}

	cout << "\nAll nodes destroyed\n\n";
}

template<typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value)
{
	TwoLinked<NODETYPE> *newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else
	{
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}
template<typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value)
{
	TwoLinked<NODETYPE> *newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else
	{
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	}
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value)
{
	if (isEmpty())
		return false;
	else
	{
		TwoLinked<NODETYPE> *tempPtr = firstPtr;

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->nextPtr;

		value = tempPtr->data;

		delete tempPtr;
		return true;
	}
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value)
{
	if (isEmpty())
		return false;
	else
	{
		TwoLinked<NODETYPE> *tempPtr = lastPtr;

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0;
		else
		{
			TwoLinked<NODETYPE> *currentPtr = firstPtr;
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;

			lastPtr = currentPtr;
			currentPtr->nextPtr = 0;
		}

		value = tempPtr->data;
		delete tempPtr;
		return true;
	}
}

template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	return firstPtr == 0;
}

template<typename NODETYPE>
TwoLinked<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value)
{
	TwoLinked<NODETYPE> *ptr = new TwoLinked<NODETYPE>(value);
	return ptr;
}

template<typename NODETYPE>
void List<NODETYPE>::print() const
{
	if (isEmpty())
	{
		cout << "The list is empty\n\n";
		return;
	}

	TwoLinked<NODETYPE> *currentPtr = firstPtr;

	cout << "The list is: ";

	while (currentPtr != 0)
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	}

	cout << "\n\n";
}

#endif
