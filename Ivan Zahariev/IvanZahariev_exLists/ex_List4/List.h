// Fig. 3.4: List.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#include "Listnode.h" // ListNode class definition

template< typename NODETYPE >
class List
{
public:
   List(); // constructor
   ~List(); // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;

   NODETYPE getFromFront();
   NODETYPE getFromBack();
   void concatenatesList(List<NODETYPE> &);
   void concatenatesList(List<NODETYPE> &, List<NODETYPE> &);
   void sortList();
   NODETYPE sum();
   double average();
   void reverse();

private:
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

// destructor
template< typename NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) // List is not empty
   {
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
      {
         tempPtr = currentPtr;
//         cout << tempPtr->data << '\n';
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      } // end while
   } // end if

//   cout << "All nodes destroyed\n\n";
} // end List destructor

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

template<typename NODETYPE>
NODETYPE List<NODETYPE>::getFromFront()
{
	NODETYPE value;
	if ( isEmpty() )
	{
		cout << "The list is empty\n\n";
		return 0;
	}

	ListNode< NODETYPE > *tempPtr = firstPtr;

	value = tempPtr->data ;

    if ( firstPtr == lastPtr )
       firstPtr = lastPtr = 0;
    else
       firstPtr = firstPtr->nextPtr;

    delete tempPtr;

    return value;
}

template<typename NODETYPE>
NODETYPE List<NODETYPE>::getFromBack() {
	NODETYPE temp;
	if ( isEmpty() )
	{
		cout << "The list is empty\n\n";
		return 0;
	}

	ListNode< NODETYPE > *tempPtr = lastPtr;

	temp = tempPtr->data ;

    if ( firstPtr == lastPtr )
       firstPtr = lastPtr = 0;
    else
    {
       ListNode< NODETYPE > *currentPtr = firstPtr;

       while ( currentPtr->nextPtr != lastPtr )
          currentPtr = currentPtr->nextPtr;

       lastPtr = currentPtr;
       currentPtr->nextPtr = 0;
    }

    delete tempPtr; // reclaim former last node

    return temp;
}

template<typename NODETYPE>
void List<NODETYPE>::concatenatesList(List<NODETYPE>& list) {
	if (list.isEmpty()) {
		cout << "Parameter list is empty." << endl;
	}

	while(list.isEmpty() != true){
		insertAtBack(list.getFromFront());
	}

}

template<typename NODETYPE>
void List<NODETYPE>::concatenatesList(List<NODETYPE>& list1, List<NODETYPE>& list2) {
	if (list1.isEmpty() || list2.isEmpty()) {
		cout << "One of parameter list is empty." << endl;
	}

	while(list1.isEmpty() != true){
		insertAtBack(list1.getFromFront());
	}
	while(list2.isEmpty() != true){
		insertAtBack(list2.getFromFront());
	}
}

template<typename NODETYPE>
void List<NODETYPE>::sortList() {
	vector<NODETYPE> temp;

	while(!isEmpty()){
		temp.push_back(getFromFront());
	}

	sort(temp.begin(), temp.end());

	for (size_t i = 0; i < temp.size(); ++i) {
		insertAtBack(temp[i]);
	}

	cout << endl;
}

template<typename NODETYPE>
NODETYPE List<NODETYPE>::sum() {
	NODETYPE sum;
	NODETYPE temp;
	List<NODETYPE> tempList;

	while(!isEmpty()){
		tempList.insertAtBack(getFromFront());
	}

	while(!tempList.isEmpty()){
		temp = tempList.getFromFront();
		insertAtBack(temp);
		sum += temp;
	}
	return sum;
}

template<typename NODETYPE>
double List<NODETYPE>::average() {
	NODETYPE sum = 0;
	NODETYPE temp;
	int count = 0;
	List<NODETYPE> tempList;

	while(!isEmpty()){
		tempList.insertAtBack(getFromFront());
	}

	while(!tempList.isEmpty()){
		temp = tempList.getFromFront();
		insertAtBack(temp);
		sum += temp;
		count++;
	}

	return (double)sum/count;
}

template<typename NODETYPE>
void List<NODETYPE>::reverse() {
	List<NODETYPE> tempList;

	while(!isEmpty()){
		tempList.insertAtBack(getFromFront());
	}

	while(!tempList.isEmpty()){
		insertAtBack(tempList.getFromBack());
	}
}
#endif

