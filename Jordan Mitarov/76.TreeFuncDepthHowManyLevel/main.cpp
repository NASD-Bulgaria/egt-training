/*8. Write a function depth that receives a binary tree
and determines how many levels it has.*/

#include <iostream>
using namespace std;

#include <iomanip>

#include "Tree.h" // Tree class definition

int main()
{
   Tree< int > intTree; // create Tree of int values
   int intValue;

   cout << "Enter 10 integer values:\n";

   // insert 10 integers to intTree
   for ( int i = 0; i < 10; i++ ) 
   {
      cin >> intValue;
      intTree.insertNode( intValue );
   } // end for

   cout << "\nPreorder traversal\n";
   intTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   intTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   intTree.postOrderTraversal();

   cout<<"\nLevels is: "<<intTree.getDepth();


   return 0;
} // end main
