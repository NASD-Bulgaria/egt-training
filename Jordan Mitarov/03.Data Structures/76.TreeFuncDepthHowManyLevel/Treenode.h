#ifndef TREENODE_H
#define TREENODE_H

template<typename T> class Tree;
// forward declaration

template<typename NODETYPE>
class TreeNode {
 friend class Tree<NODETYPE> ;
public:
 TreeNode(const NODETYPE &); // constructor
 NODETYPE getData() const; // return data

 TreeNode *getLeftPtr() const {
  return leftPtr;
 }
 TreeNode *getRightPtr() const {
  return rightPtr;
 }
 void setLeftPtr(TreeNode *ptr) {
  leftPtr = ptr;
 }

 // set value for rightPtr
 void setRightPtr(TreeNode *ptr) {
  rightPtr = ptr;
 }
private:
 TreeNode *leftPtr;
 NODETYPE data;
 TreeNode *rightPtr;
};

// constructor
template<typename NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &d) {
 data = d;
 leftPtr = rightPtr = 0;
}

// return a copy of the data value
template<typename NODETYPE>
NODETYPE TreeNode<NODETYPE>::getData() const {
 return data;
} // end function getData

#endif

