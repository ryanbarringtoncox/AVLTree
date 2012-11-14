#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
private:
	T value;
	int balance;
	Node<T>* leftChild;
	Node<T>* rightChild;
	Node<T>* parent;
	
public:
	Node<T>(T v);
	T getValue();	
	int getBalance();
	void incBalance();
	void decBalance();
	void resetBalance();
	void nullParent();	
	
	Node<T>*& getLeftChild();
	void setLeftChild(Node<T>& n);
	
	Node<T>*& getRightChild();
	void setRightChild(Node<T>& n);
	
	Node<T>*& getParent();
	void setParent(Node<T>& n);	
};
#endif
