// Fig. 3.4: List.h
// Template List class definition.

#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;

#include "Listnode.h" // ListNode class definition

template< typename NODETYPE >
class List
{
public:
	List(); // constructor
	List( const List< NODETYPE > & ); // copy constructor
	~List(); // destructor
	void insertAtFront( const NODETYPE & );
	void insertAtBack( const NODETYPE & );
	void insertInOrder(const NODETYPE &);
	bool removeFromFront( NODETYPE & );
	bool removeFromBack( NODETYPE & );
	bool isEmpty() const;
	void print() const;
	void concadList( List<NODETYPE> &);

protected:
	ListNode< NODETYPE > *firstPtr; // pointer to first node
	ListNode< NODETYPE > *lastPtr; // pointer to last node

// utility function to allocate new node
ListNode< NODETYPE > *getNewNode( const NODETYPE & );
}; // end class List

// default constructor
template< typename NODETYPE >
List< NODETYPE >::List()
: firstPtr( 0 ), lastPtr( 0 )
{
// empty body
} // end List constructor
// copy constructor
template< typename NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
	firstPtr = lastPtr = 0; // initialize pointers

	ListNode< NODETYPE > *currentPtr = copy.firstPtr;

	// insert into the list
	while ( currentPtr != 0 )
	{
		insertAtBack( currentPtr->data );
		currentPtr = currentPtr->nextPtr;
	} // end while
} // end List copy constructor


// destructor
template< typename NODETYPE >
List< NODETYPE >::~List()
{
	if ( !isEmpty() ) // List is not empty
	{
		cout << "Destroying nodes ...\n";

		ListNode< NODETYPE > *currentPtr = firstPtr;
		ListNode< NODETYPE > *tempPtr;

		while ( currentPtr != 0 ) // delete remaining nodes
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		} // end while
	} // end if

cout << "All nodes destroyed\n\n";
} // end List destructor

template< typename T >
void concatenate( List< T > &first, List< T > &second )
{
	 List< T > temp( second ); // create a copy of second
	 T value; // variable to store removed item from temp

	 while ( !temp.isEmpty() )
	 {
		 temp.removeFromFront( value ); // remove value from temp list
		 first.insertAtBack( value ); // insert at end of first list
	 } // end loop
} // end function concatenate

// insert node at front of list
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
	ListNode< NODETYPE > *newPtr = getNewNode( value ); // new node

	if ( isEmpty() ) // List is empty
		firstPtr = lastPtr = newPtr; // new list has only one node
	else // List is not empty
	{
		newPtr->nextPtr = firstPtr; // point new node to previous 1st node
		firstPtr = newPtr; // aim firstPtr at new node
	} // end else
} // end function insertAtFront

// insert node at back of list
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
	ListNode< NODETYPE > *newPtr = getNewNode( value ); // new node

	if ( isEmpty() ) // List is empty
		firstPtr = lastPtr = newPtr; // new list has only one node
	else // List is not empty
	{
		lastPtr->nextPtr = newPtr; // update previous last node
		lastPtr = newPtr; // new last node
	} // end else
} // end function insertAtBack

// delete node from front of list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
	if ( isEmpty() ) // List is empty
		return false; // delete unsuccessful
	else
	{
		ListNode< NODETYPE > *tempPtr = firstPtr; // hold tempPtr to delete

		if ( firstPtr == lastPtr )
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else
			firstPtr = firstPtr->nextPtr; // point to previous 2nd node

			value = tempPtr->data; // return data being removed
			delete tempPtr; // reclaim previous front node
			return true; // delete successful
	} // end else
} // end function removeFromFront

// delete node from back of list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
	if ( isEmpty() ) // List is empty
		return false; // delete unsuccessful
	else
	{
		ListNode< NODETYPE > *tempPtr = lastPtr; // hold tempPtr to delete

		if ( firstPtr == lastPtr ) // List has one element
			firstPtr = lastPtr = 0; // no nodes remain after removal
		else
		{
			ListNode< NODETYPE > *currentPtr = firstPtr;

		// locate second-to-last element
			while ( currentPtr->nextPtr != lastPtr )
				currentPtr = currentPtr->nextPtr; // move to next node

				lastPtr = currentPtr; // remove last node
				currentPtr->nextPtr = 0; // this is now the last node
		} // end else

		value = tempPtr->data; // return value from old last node
		delete tempPtr; // reclaim former last node
		return true; // delete successful
	} // end else
} // end function removeFromBack

// is List empty?
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
	return firstPtr == 0;
} // end function isEmpty

// return pointer to newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
const NODETYPE &value )
{
	return new ListNode< NODETYPE >( value );
} // end function getNewNode

// display contents of List
template< typename NODETYPE >
void List< NODETYPE >::print() const
{
	if ( isEmpty() ) // List is empty
	{
		cout << "The list is empty\n\n";
		return;
	} // end if

	ListNode< NODETYPE > *currentPtr = firstPtr;

	cout << "The list is: ";

	while ( currentPtr != 0 ) // get element data
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	} // end while

	cout << "\n\n";
} // end function print


//insert a node in order
template<typename NODETYPE>
void List<NODETYPE>::insertInOrder(const NODETYPE &value)
{
	if(isEmpty()) //list is empty
	{
		ListNode<NODETYPE> *newPtr = getNewNode(value);
		firstPtr = lastPtr = newPtr;
	}

	else //list is not empty
	{
		if(firstPtr->getData() > value)
			insertAtFront(value);
		else if(lastPtr->getData()<value)
			insertAtBack(value);
		else
		{
			ListNode< NODETYPE > *currentPtr = firstPtr->getNextPtr();
			ListNode< NODETYPE > *previousPtr = firstPtr;
			ListNode< NODETYPE > *newPtr = getNewNode( value );

			while(currentPtr !=lastPtr && currentPtr->getData() < value)
			{
				previousPtr = currentPtr;
				currentPtr = currentPtr -> getNextPtr();
			}

			previousPtr->setNextPtr(newPtr);
			newPtr->setNextPtr(currentPtr);
		}
	}
}

#endif
