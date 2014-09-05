/*
 * TreeNode.h
 *
 *  Created on: Sep 3, 2014
 *      Author: NandM
 */

#ifndef TREENODE_H_
#define TREENODE_H_

template <typename T> class BinaryTree;

template<typename T>
class TreeNode{
	friend class BinaryTree<T>;
public:
	TreeNode(T data);
	~TreeNode();
	const T getData() const;
private:
	TreeNode * leftNode;
	TreeNode * rightNode;
	T data;
};

template<typename T>
inline TreeNode<T>::TreeNode(T data)
	:leftNode(0), rightNode(0), data(data){
}

template<typename T>
inline TreeNode<T>::~TreeNode() {
}

template<typename T>
inline const T TreeNode<T>::getData() const {
	return data;
}

#endif /* TREENODE_H_ */
