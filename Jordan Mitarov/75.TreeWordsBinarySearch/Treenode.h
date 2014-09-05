/*Write a program based on Figs. 24.20 24.22 that
inputs a line of text, tokenizes the sentence into
separate words (you may want to use the strtok
library function), inserts the words in a binary
search tree and prints the inorder, preorder and
postorder traversals of the tree. Use an OOP
approach.*/

#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template< typename NODETYPE > class Tree;  

// TreeNode class-template definition
template< typename NODETYPE >
class TreeNode 
{
   friend class Tree< NODETYPE >;
public:
   // constructor
   TreeNode( const NODETYPE &d )   
      : leftPtr( 0 ), // pointer to left subtree
        data( d ), // tree node data
        rightPtr( 0 ) // pointer to right substree
   { 
      // empty body 
   } // end TreeNode constructor

   // return copy of node's data
   NODETYPE getData() const 
   { 
      return data; 
   } // end getData function
private:
   TreeNode< NODETYPE > *leftPtr; // pointer to left subtree
   NODETYPE data;
   TreeNode< NODETYPE > *rightPtr; // pointer to right subtree
}; // end class TreeNode

#endif

