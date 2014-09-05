/*
 * OrderedLinkedList.h
 *
 *  Created on: Sep 2, 2014
 *      Author: NandM
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
class OrderedLinkedList: private LinkedList<T> {
public:
	OrderedLinkedList();
	virtual ~OrderedLinkedList();
	void add(ListNode<T> &);
	const virtual int getCount() const;
	virtual ListNode<T>* popBack();
	virtual ListNode<T>* popHead();
	virtual void printBackward();
	virtual void printForward();
	void mergeList(OrderedLinkedList<T> &);
private:
};

template<typename T>
inline OrderedLinkedList<T>::OrderedLinkedList() :
		LinkedList<T>() {
}

template<typename T>
inline OrderedLinkedList<T>::~OrderedLinkedList() {
}

template<typename T>
inline void OrderedLinkedList<T>::add(ListNode<T>& listNode) {
	this->sortedInsert(listNode);
}

template<typename T>
inline ListNode<T>* OrderedLinkedList<T>::popBack() {
	return LinkedList<T>::popBack();
}

template<typename T>
inline ListNode<T>* OrderedLinkedList<T>::popHead() {
	return LinkedList<T>::popHead();
}

template<typename T>
inline const int OrderedLinkedList<T>::getCount() const {
	return LinkedList<T>::getCount();
}

template<typename T>
inline void OrderedLinkedList<T>::printBackward() {
	LinkedList<T>::printBackward();
}

template<typename T>
inline void OrderedLinkedList<T>::printForward() {
	LinkedList<T>::printForward();
}

template<typename T>
inline void OrderedLinkedList<T>::mergeList(
		OrderedLinkedList<T>& orderedLinkedList) {
	while (orderedLinkedList.getCount() > 0) {
		this->sortedInsert(*orderedLinkedList.popBack());
	}
}

#endif /* ORDEREDLINKEDLIST_H_ */
