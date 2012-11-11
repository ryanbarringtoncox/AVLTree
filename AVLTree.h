#ifndef __AVL_H__
#define __AVL_H__

#include "Node.h"
#include "Glob.h"
#include "TwoDArray.h"
#include <string>

template <typename T>
class BST {
private:
	Node<T>* root;
	void traversalPrint(Node<T>* root);
	
public:
	BST<T>();
	~BST<T>();
	
	bool find(T v);
	void remove(T v);
	void insert(T v);
	void print();
	void visualPrint(T def, T leftLeg, T rightLeg);
};


#endif
