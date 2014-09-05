#ifndef LIST2_H
 #define LIST2_H

#include "TwoLinked.h"
 #include "List.h"

 template< typename NODETYPE >
 class List2 : public List< NODETYPE >
 {
 public:
 void insertInOrder( const NODETYPE & );
 };


 template< typename NODETYPE >
 void List2< NODETYPE >::insertInOrder( const NODETYPE &value )
{
 if ( isEmpty() )
 {
	 TwoLinked< NODETYPE > *newPtr = getNewNode( value );
 firstPtr = lastPtr = newPtr;
 }
 else
 {
 if ( firstPtr->getData() > value )
 insertAtFront( value );
 else if ( lastPtr->getData() < value )
 insertAtBack( value );
 else
 {
	 TwoLinked< NODETYPE > *currentPtr = firstPtr->getNextPtr();
	 TwoLinked< NODETYPE > *previousPtr = firstPtr;
	 TwoLinked< NODETYPE > *newPtr = getNewNode( value );

 while ( currentPtr != lastPtr && currentPtr->getData() < value )
 {
 previousPtr = currentPtr;
 currentPtr = currentPtr->getNextPtr();
 }

 previousPtr->setNextPtr( newPtr );
 newPtr->setNextPtr( currentPtr );
 }
 }
 }

 #endif
