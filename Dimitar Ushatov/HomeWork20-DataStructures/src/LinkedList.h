/*
 * LinkedList.h
 *
 *  Created on: Sep 2, 2014
 *      Author: NandM
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstdlib>
#include <iostream>
#include "ListNode.h"

using namespace std;

template<typename T>
class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();
	const virtual int getCount() const;
	void addHead(ListNode<T>& node);
	void addBack(ListNode<T>& node);
	virtual ListNode<T> * popHead();
	virtual ListNode<T> * popBack();
	virtual void mergeList(LinkedList<T> &);
	virtual void printBackward();
	virtual void printForward();
	ListNode<T> * searchList(T value);
	void sortedInsert(ListNode<T>& node);
private:
	ListNode<T> * firstNode;
	ListNode<T> * lastNode;
	int count;

	void addFirst(ListNode<T> & node);
	void recursiveBackPrint(ListNode<T> * ptr);
	void recursiveForwardPrint(ListNode<T> * ptr);
	ListNode<T> * searchHelper(T value, ListNode<T> * ptr);
};

template<typename T>
inline void LinkedList<T>::printBackward() {
	recursiveBackPrint(firstNode);
}

template<typename T>
inline void LinkedList<T>::printForward() {
	recursiveForwardPrint(lastNode);
}

template<typename T>
inline void LinkedList<T>::recursiveBackPrint(ListNode<T>* ptr) {
	if (ptr != 0) {
		cout<<ptr->getData() << " ";
		recursiveBackPrint(ptr->previousPtr);
	}
}

template<typename T>
inline ListNode<T>* LinkedList<T>::searchList(T value) {
	return searchHelper(value, lastNode);
}

template<typename T>
inline void LinkedList<T>::recursiveForwardPrint(ListNode<T>* ptr) {
	if (ptr != 0) {
		cout<<ptr->getData() << " ";
		recursiveForwardPrint(ptr->nextPtr);
	}
}

template<typename T>
inline LinkedList<T>::LinkedList() :
		firstNode(NULL), lastNode(NULL), count(0) {
}

template<typename T>
inline LinkedList<T>::~LinkedList() {
	ListNode<T> * ptr = lastNode;
	ListNode<T> * temp = 0;
	while(ptr != 0){
		temp = ptr->nextPtr;
		delete ptr;
		ptr = temp;
	}
}

template<typename T>
inline const int LinkedList<T>::getCount() const {
	return this->count;
}

template<typename T>
inline void LinkedList<T>::addHead(ListNode<T>& node) {
	if (this->getCount() == 0) {
		this->addFirst(node);
	} else {
		node.nextPtr = NULL;
		firstNode->nextPtr = &node;
		node.previousPtr = firstNode;
		firstNode = &node;
		count++;
	}
}

template<typename T>
inline void LinkedList<T>::addBack(ListNode<T>& node) {
	if (this->getCount() == 0) {
		this->addFirst(node);
	} else {
		node.nextPtr = lastNode;
		lastNode->previousPtr = &node;
		node.previousPtr = NULL;
		lastNode = &node;
		count++;
	}
}

template<typename T>
inline ListNode<T>* LinkedList<T>::popHead() {
	if (this->getCount() > 0) {
		ListNode<T>* node = firstNode;
		if (node->previousPtr) {
			firstNode = node->previousPtr;
			firstNode->nextPtr = NULL;
			node->previousPtr = NULL;
		}
		count--;
		return node;
	} else {
		cerr << "Empty list!";
		exit(1);
	}
}

template<typename T>
inline ListNode<T>* LinkedList<T>::popBack() {
	if (this->getCount() > 0) {
		ListNode<T> * node = lastNode;
		lastNode = node->nextPtr;
		if (lastNode != 0) {
			lastNode->previousPtr = 0;
		}
		node->nextPtr = 0;
		count--;
		return node;
	} else {
		cerr << "Empty List!";
		exit(1);
	}
}

template<typename T>
inline void LinkedList<T>::sortedInsert(ListNode<T>& node) {
	if (this->getCount() == 0) {
		addFirst(node);
	} else {
		ListNode<T> * current = lastNode;
		while (current != 0) {
			if (current->data >= node.data) {
				break;
			}
			current = current->nextPtr;
		}
		if (current != 0) {
			if (current->previousPtr != 0) {
				ListNode<T>* prePtr = current->previousPtr;
				prePtr->nextPtr = &node;
				node.previousPtr = prePtr;
				current->previousPtr = &node;
				node.nextPtr = current;
				this->count++;
			} else {
				addBack(node);
			}
		} else {
			addHead(node);
		}
	}
}

template<typename T>
inline void LinkedList<T>::mergeList(LinkedList<T>& linkedList) {
	ListNode<T>* first = firstNode;
	if (linkedList.lastNode != 0) {
		first->nextPtr = linkedList.lastNode;
		ListNode<T>* lastLeft = linkedList.lastNode;
		lastLeft->previousPtr = first;
	}
	if (linkedList.firstNode != 0) {
		firstNode = linkedList.firstNode;
	}
	count += linkedList.count;
}

template<typename T>
inline void LinkedList<T>::addFirst(ListNode<T>& node) {
	this->lastNode = this->firstNode = &node;
	this->count++;
}

template<typename T>
inline ListNode<T>* LinkedList<T>::searchHelper(T value, ListNode<T>* ptr) {
	if (ptr != 0) {
		if (ptr->data == value) {
			return ptr;
		}
		return searchHelper(value, ptr->nextPtr);
	}
	return 0;
}

#endif /* LINKEDLIST_H_ */
