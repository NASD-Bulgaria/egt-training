/*
 * ListNode.h
 *
 *  Created on: Sep 2, 2014
 *      Author: NandM
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <iostream>
using namespace std;

template <typename T> class LinkedList;

template <typename T>
class ListNode {

	friend class LinkedList<T>;

public:
	ListNode(T data);
	ListNode(ListNode<T> & value);
	~ListNode();
	T getData() const;

private:
	T data;
	ListNode<T> * nextPtr;
	ListNode<T> * previousPtr;
};

template<typename T>
inline ListNode<T>::ListNode(ListNode<T>& value) {
	this->data = value.data;
	this->nextPtr = value.nextPtr;
	this->previousPtr = value.previousPtr;
}

template<typename T>
inline ListNode<T>::~ListNode() {
}

template<typename T>
inline ListNode<T>::ListNode(T data)
	: nextPtr(NULL), previousPtr(NULL) {
	this->data = data;
}

template <typename T>
inline T ListNode<T>::getData() const {
	return data;
}

#endif /* LISTNODE_H_ */
