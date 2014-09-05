///*
// * List2.h
// *
// *  Created on: 4.09.2014 г.
// *      Author: стаса
// */
//
//#ifndef LIST2_H_
//#define LIST2_H_
//
//#include "TwoLinked.h"
// #include "List.h"
//
// template< typename NODETYPE >
// class List2 : public List< NODETYPE >
// {
// public:
// void insertInOrder( const NODETYPE & );
// };
//
//
// template< typename NODETYPE >
// void List2< NODETYPE >::insertInOrder( const NODETYPE &value )
//{
// if ( this->isEmpty() )
// {
//	 TwoLinked< NODETYPE > *newPtr = this->getNewNode( value );
//	 this->firstPtr = this->lastPtr = newPtr;
// }
// else
// {
// if ( this->firstPtr->getData() > value )
// this->insertAtFront( value );
// else if ( this->lastPtr->getData() < value )
// this->insertAtBack( value );
// else
// {
//	 TwoLinked< NODETYPE > *currentPtr = this->firstPtr->getNextPtr();
//	 TwoLinked< NODETYPE > *previousPtr = this->firstPtr;
//	 TwoLinked< NODETYPE > *newPtr = this->getNewNode( value );
//
// while ( currentPtr != this->lastPtr && currentPtr->getData() < value )
// {
// previousPtr = currentPtr;
// currentPtr = currentPtr->getNextPtr();
// }
//
// previousPtr->setNextPtr( newPtr );
// newPtr->setNextPtr( currentPtr );
// }
// }
// }
//
//
//
//
//
//#endif
