///*
// * MergeTwoLists.cpp
// *
// *  Created on: 4.09.2014 г.
// *      Author: стаса
// */
//
//#include <iostream>
//#include "List.h"
//using namespace std;
//
//template<typename T>
//void merge(List<T> &first, List<T> &second, List<T> &result)
//{
//	List<T> tempFirst(first);
//	List<T> tempSecond(second);
//	T value1;
//	T value2;
//
//	tempFirst.removeFromFront(value1);
//	tempSecond.removeFromFront(value2);
//
//	while (!tempFirst.isEmpty() && !tempSecond.isEmpty())
//	{
//		if (value1 <= value2)
//		{
//			result.insertAtBack(value1);
//			tempFirst.removeFromFront(value1);
//		}
//		else
//		{
//			result.insertAtBack(value2);
//			tempSecond.removeFromFront(value2);
//		}
//	}
//
//	if (value1 < value2)
//	{
//		result.insertAtBack(value1);
//		result.insertAtBack(value2);
//	}
//	else
//	{
//		result.insertAtBack(value2);
//		result.insertAtBack(value1);
//	}
//
//	if (!tempFirst.isEmpty()) // items left in tempFirst
//	{
//		do
//		{
//			tempFirst.removeFromFront(value1);
//			result.insertAtBack(value2);
//		} while (!tempFirst.isEmpty());
//	}
//	else
//	{
//		do
//		{
//			tempSecond.removeFromFront(value2);
//			result.insertAtBack(value2);
//		} while (!tempSecond.isEmpty());
//	}
//}
//
//int main()
//{
//	List<int> list1;
//	List<int> list2;
//	List<int> result;
//	int i;
//
//	for (i = 1; i <= 9; i += 2)
//		list1.insertAtBack(i);
//
//	list1.print();
//
//	for (i = 2; i <= 10; i += 2)
//		list2.insertAtBack(i);
//
//	list2.print();
//
//	merge(list1, list2, result);
//
//	cout << "The merged list is:\n";
//	result.print();
//	return 0;
//}
//
//
//
