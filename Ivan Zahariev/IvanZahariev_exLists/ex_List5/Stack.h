// Fig. 3.13: Stack.h
// Template Stack class definition derived from class List.
#ifndef STACK_H
#define STACK_H

#include "List.h" // List class definition
#include <vector>

template< typename STACKTYPE >
class Stack : private List< STACKTYPE >
{
public:
	// push calls the List function insertAtFront
	void push( const STACKTYPE &data )
	{
		List<STACKTYPE>::insertAtFront(data);
//      insertAtFront( data );
	} // end function push

	// pop calls the List function removeFromFront
	bool pop( STACKTYPE &data )
	{
		return List<STACKTYPE>::removeFromFront( data );
	} // end function pop

	// isStackEmpty calls the List function isEmpty
	bool isStackEmpty() const
	{
		return List<STACKTYPE>::isEmpty();
	} // end function isStackEmpty
 
	// printStack calls the List function print
	void printStack() const
	{
		List<STACKTYPE>::print();
	} // end function print

	bool palindrome();
};
// end class Stack

template<typename STACKTYPE>
bool Stack<STACKTYPE>::palindrome() {
	STACKTYPE temp;
	bool check = true;
	List<STACKTYPE> tempList;
	Stack<STACKTYPE> tempStack;
	STACKTYPE tmp;

	while(!isStackEmpty()){
		pop(temp);
		tempList.insertAtFront(temp);
		tempStack.push(temp);
	}

	while(!tempList.isEmpty()){
		tempList.removeFromBack(temp);
		push(temp);
		tempStack.pop(tmp);
		if (temp != tmp) {
			check = false;
		}
	}

	return check;
}

#endif

