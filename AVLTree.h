#ifndef __AVL_H__
#define __AVL_H__

#include "Node.h"
#include "Glob.h"
#include "TwoDArray.h"
#include <string>

template <typename T>
class AVLTree {
private:
	Node<T>* root;
	Node<T>* cn;
	void traversalPrint(Node<T>* root);
	void traversalPrintPost(Node<T>* root);	
	void traversalPrintIn(Node<T>* root);		
	void leftRotation(Node<T>* cn, Node<T>** parent);
	void rightRotation(Node<T>* cn, Node<T>** parent);	
	
public:
	AVLTree<T>();
	~AVLTree<T>();
	bool find(T v);
	bool isRoot(Node<T>* n);
	void remove(T v);
	void insert(T v);
	void print();
	void visualPrint(T def, T leftLeg, T rightLeg);
	void postOrderTraversal();
	void inOrderTraversal();
};


#endif
