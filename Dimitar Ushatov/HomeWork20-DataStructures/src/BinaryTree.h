/*
 * BinaryTree.h
 *
 *  Created on: Sep 3, 2014
 *      Author: NandM
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

template<typename T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(TreeNode<T>& root);
	const TreeNode<T> * getRoot() const;
	void printPreOrder();
	void printPostOrder();
	void printInOrder();
	void insert(TreeNode<T> &);
	const TreeNode<T>* const search(const TreeNode<T>* const root, T value);
	~BinaryTree();
	int getDepth();
private:
	TreeNode<T>* root;
	int depth;
	void recursiveInsert(TreeNode<T> &, TreeNode<T>* ptr);
	void recursivePreOrder(TreeNode<T>* ptr);
	void recursivePostOrder(TreeNode<T>* ptr);
	void recursiveInOrder(TreeNode<T>* ptr);
	int maxDepth(TreeNode<T> * ptr);
};

template<typename T>
inline BinaryTree<T>::BinaryTree() :
		root(0), depth(0) {
}

template<typename T>
inline BinaryTree<T>::BinaryTree(TreeNode<T>& root) :
		root(root), depth(1) {
}

template<typename T>
inline const TreeNode<T>* BinaryTree<T>::getRoot() const {
	return root;
}

template<typename T>
inline void BinaryTree<T>::printPreOrder() {
	recursivePreOrder(root);
}

template<typename T>
inline void BinaryTree<T>::printPostOrder() {
	recursivePostOrder(root);
}

template<typename T>
inline void BinaryTree<T>::printInOrder() {
	recursiveInOrder(root);
}

template<typename T>
inline void BinaryTree<T>::insert(TreeNode<T>& treeNode) {
	if (root != 0) {
		recursiveInsert(treeNode, root);
	} else {
		root = &treeNode;
		depth = 1;
	}
}

template<typename T>
inline BinaryTree<T>::~BinaryTree() {
}

template<typename T>
int BinaryTree<T>::getDepth() {
	return maxDepth(this->root);
}

template<typename T>
inline void BinaryTree<T>::recursiveInsert(TreeNode<T>& treeNode,
		TreeNode<T>* ptr) {
	if (ptr->data < treeNode.data) {
		if (ptr->rightNode != 0) {
			recursiveInsert(treeNode, ptr->rightNode);
		} else {
			ptr->rightNode = &treeNode;
		}
	} else if (ptr->data > treeNode.data) {
		if (ptr->leftNode != 0) {
			recursiveInsert(treeNode, ptr->leftNode);
		} else {
			ptr->leftNode = &treeNode;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::recursivePreOrder(TreeNode<T>* ptr) {
	if (ptr != 0) {
		cout << ptr->getData() << " ";
		recursivePreOrder(ptr->leftNode);
		recursiveInOrder(ptr->rightNode);
	}
}

template<typename T>
inline void BinaryTree<T>::recursivePostOrder(TreeNode<T>* ptr) {
	if (ptr != 0) {
		recursivePostOrder(ptr->leftNode);
		recursivePostOrder(ptr->rightNode);
		cout << ptr->getData() << " ";
	}
}

template<typename T>
inline void BinaryTree<T>::recursiveInOrder(TreeNode<T>* ptr) {
	if (ptr != 0) {
		recursiveInOrder(ptr->leftNode);
		cout << ptr->getData() << " ";
		recursiveInOrder(ptr->rightNode);
	}
}

template<typename T>
inline const TreeNode<T>* const BinaryTree<T>::search(
		const TreeNode<T>* const root, T value) {
	if (root) {
		if (root->data == value) {
			return root;
		}
		if (root->data > value) {
			return search(root->leftNode, value);
		}
		if (root->data < value) {
			return search(root->rightNode, value);
		}
	}
	return 0;
}

template<typename T>
inline int BinaryTree<T>::maxDepth(TreeNode<T>* ptr) {
	if (!ptr) {
		return 0;
	}
	int leftDepth = maxDepth(ptr->leftNode);
	int rightDepth = maxDepth(ptr->rightNode);
	return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

#endif /* BINARYTREE_H_ */
