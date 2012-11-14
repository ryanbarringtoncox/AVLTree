#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(T v) {
	value = v;
	leftChild = 0;
	rightChild = 0;
	parent = 0;
	balance = 0;
}

template <typename T>
void Node<T>::nullParent() {
	parent=0;;
}

template <typename T>
T Node<T>::getValue() {
	return value;
}

template <typename T>
int Node<T>::getBalance() {
	return balance;
}

template <typename T>
void Node<T>::incBalance() {
	++balance;
}

template <typename T>
void Node<T>::decBalance() {
	--balance;
}

template <typename T>
void Node<T>::resetBalance() {
	balance = 0;
}

template <typename T>
Node<T>*& Node<T>::getLeftChild() {
	return leftChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>& lc) {
	leftChild = &lc;
}

template <typename T>
Node<T>*& Node<T>::getRightChild() {
	return rightChild;
}

template <typename T>
void Node<T>::setRightChild(Node<T>& rc) {
	rightChild = &rc;
}

template <typename T>
Node<T>*& Node<T>::getParent() {
	return parent;
}

template <typename T>
void Node<T>::setParent(Node<T>& p) {
	parent = &p;
	if (parent->getValue() > this->getValue()) parent->setLeftChild(*this);
	else parent->setRightChild(*this);
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

