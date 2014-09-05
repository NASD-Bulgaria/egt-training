///*
// * TwoLinked.h
// *
// *  Created on: 4.09.2014 г.
// *      Author: стаса
// */
//
//#ifndef TWOLINKED_H_
//#define TWOLINKED_H_
//
//template<typename T> class List;
//
//template<typename NODETYPE>
//class TwoLinked
//{
//	friend class List<NODETYPE>;
//public:
//	TwoLinked(const NODETYPE &);
//	NODETYPE getData() const;
//
//	void setNextPtr(TwoLinked *nPtr)
//	{
//		nextPtr = nPtr;
//	}
//
//	TwoLinked *getNextPtr() const
//	{
//		return nextPtr;
//	}
//
//private:
//	NODETYPE data;
//	TwoLinked *nextPtr;
//};
//
//template<typename NODETYPE>
//TwoLinked<NODETYPE>::TwoLinked(const NODETYPE &info)
//{
//	data = info;
//	nextPtr = 0;
//}
//template<typename NODETYPE>
//NODETYPE TwoLinked<NODETYPE>::getData() const
//{
//	return data;
//}
//
//#endif
