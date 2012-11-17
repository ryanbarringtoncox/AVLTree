#include "AVLTree.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;
using std::cout;
using std::endl;

template <typename T>
AVLTree<T>::AVLTree() {
	root = 0;
}

template <typename T>
AVLTree<T>::~AVLTree() {
	
}

template <typename T>
bool AVLTree<T>::find(T v) {
	Node<T>** curr =&root;
	
	while(*curr!=0 && (*curr)->getValue()!= v) {
		if (v < (*curr)->getValue()) {
			curr = &((*curr)->getLeftChild());
		} else if (v > (*curr)->getValue()) {
			curr = &((*curr)->getRightChild());
		}    
	}
	
	if (*curr==0) {
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
bool AVLTree<T>::isRoot(Node<T>* n) {
	if (n == root) return true;
	else return false;
}


template <typename T>
void AVLTree<T>::insert(T v) {
	Node<T>* temp = new Node<T>(v);
	Node<T>** curr = &root;

	//double rotation flags
	bool rightLeft = false;
	bool leftRight = false;
	
	//tree is empty, insert at root
	if (*curr == 0) {
		*curr = temp;			
	}
	
	else {

		//keep a parent pointer
		Node<T>** dad = &root;
		
		//Critical node is null by default
		cn = 0;
		
		//find spot for new node, keep track of potential cns
		while (*curr != 0) {
			
			if (v == (*curr)->getValue()) return;
			
			if (v < (*curr)->getValue()) {
				if ((*curr)->getBalance() == -1) {
					cn = *curr;
					dad = &*curr;
				}
				if (cn && cn->getBalance() > 0) {
					cout << "Rotate right then left" << endl;
					rightLeft = true;
				}
				curr = &((*curr)->getLeftChild());
			} else if (v > (*curr)->getValue()) {
				if ((*curr)->getBalance() == 1) {
					cn = *curr;	
					dad = &*curr;
				}
				if (cn && cn->getBalance() < 0) {
					cout << "Rotate left then right" << endl;
					leftRight = true;
				}
				curr = &((*curr)->getRightChild());
			}
		}
		
		//insert the node
		*curr = temp;	
		
		
		//no cn, update balances
		if (!cn) {			
			curr = &root;
			while (*curr != 0) {
				if (v < (*curr)->getValue()) {
					(*curr)->decBalance();
					curr = &((*curr)->getLeftChild());
				} else if (v > (*curr)->getValue()) {
					(*curr)->incBalance();					
					curr = &((*curr)->getRightChild());
				}
				else if (v == (*curr)->getValue()) break;
			}			
		}		
		
		//single rotations
		if (cn && !rightLeft && !leftRight) {			
			//cout << "Cn found: " << cn->getValue() << endl;
			curr = &cn;
			
			if ((*curr)->getBalance() == -1) {	
				rightRotation(cn, dad);
			}
			
			if ((*curr)->getBalance()== 1) {	
				leftRotation(cn, dad);
			}
			
			//reset cn balance to zero
			cn->resetBalance();			
			
		}
			
		//double rotations
		if (cn && rightLeft) {
			rightRotation(cn->getRightChild(), &(cn->getRightChild()));
			leftRotation(cn, dad);
			cn->resetBalance();
		}
		if (cn && leftRight) {
			leftRotation(cn->getLeftChild(), &(cn->getLeftChild()));
			rightRotation(cn, dad);
			cn->resetBalance();
		}
	}
}

template <typename T>
void AVLTree<T>::rightRotation(Node<T>* cn, Node<T>** parent) {	
	cout << "Right rotation on " << cn->getValue() << endl;
	Node<T>* newRoot = cn->getLeftChild();
	Node<T>* tempRC = newRoot->getRightChild();	
	*parent = newRoot;
	newRoot->setRightChild(*cn);
	cn->setLeftChild(*tempRC);	

	//special case
	if (tempRC != 0 && newRoot->getLeftChild() != 0) newRoot->getLeftChild()->decBalance();
}

template <typename T>
void AVLTree<T>::leftRotation(Node<T>* cn, Node<T>** parent) {
	cout << "Left Rotation on " << cn->getValue() << endl;
	Node<T>* newRoot = cn->getRightChild();
	Node<T>* tempLC = newRoot->getLeftChild();
	*parent = newRoot;
	newRoot->setLeftChild(*cn);
	cn->setRightChild(*tempLC);	
	
	//special case
	if (tempLC != 0 && newRoot->getRightChild() != 0) newRoot->getRightChild()->incBalance();
}

template <typename T>
void AVLTree<T>::remove(T v) {
	Node<T>** curr =&root;
	Node<T>** mom;
		vector<Node<T>**> path;
	
	//is v in tree?
	while(*curr!=0 && (*curr)->getValue()!= v) {
		path.push_back(curr);
		if (v < (*curr)->getValue()) {
			curr = &((*curr)->getLeftChild());
		} else if (v > (*curr)->getValue()) {
			curr = &((*curr)->getRightChild());
		}    
	}
	
	//v not found
	if (*curr==0) {
		return;
	}
	
	//v is Found
	else {
		Node<T>* nodeToRemove = *curr;	
		//no left child
		if ((nodeToRemove)->getLeftChild()==0) {
			*curr=nodeToRemove->getRightChild();
		}
		//if there's a left child find in-order-predecessor
		else {
			Node<T>* iop = nodeToRemove->getLeftChild();
			while (iop->getRightChild()!=0) {
				iop = iop->getRightChild();	
			}
			iop->setRightChild(*(nodeToRemove->getRightChild()));
			*curr=nodeToRemove->getLeftChild();
		}	  
		
		//update balances through path to root
		T currValue = v;
		mom=&*(path.back());
		
		//increment parent as necessary
		if (currValue < ((*mom))->getValue()) (*mom)->incBalance();
		if (currValue > (*mom)->getValue()) (*mom)->decBalance();

		//keep going with grandparents
		while ((*mom)->getBalance()!=1 && (*mom)->getBalance()!=-1) {		
			
			//rotations
			if ((*mom)->getBalance()==2) {
				(*mom)->resetBalance();
				leftRotation(*mom, mom);
				(*mom)->decBalance();
				
			}			
			if ((*mom)->getBalance()==-2) {
				(*mom)->resetBalance();
				rightRotation(*mom, mom);
				(*mom)->incBalance();
				
			}
			
			//balance adjustments
			if ((*mom)->getBalance()==0) {				
				currValue = (*mom)->getValue();
				path.pop_back();
				if (*mom == root) break;
				mom=&*(path.back());
				if (*mom) {			
					if (currValue < (*mom)->getValue()) (*mom)->incBalance();
					if (currValue > (*mom)->getValue()) (*mom)->decBalance();	
				}
			}
			
		}
		delete nodeToRemove;
	}
}

template <typename T>
void AVLTree<T>::visualPrint(T def, T leftLeg, T rightLeg) {
	
	//make a Queue of globs, push in root at 0, 0
	list<Glob<T>*> q;
	int level=0; int spread=0;
	Glob<T>* root_glob = new Glob<T>(*root, level, spread);
	q.push_back (root_glob);
	
	//make 2d vector for glob coordinates, spread is width, level is depth
	int s; int l;
	TwoDArray<T>* tda = new TwoDArray<T>(8, 15, def);
	int spread_middle = 7;
	
	//begin level order traversal of AVLTree and insert into tda
	Node<T>* curr_node;
	while (!(q.empty())) {
		Glob<T>* curr_glob = q.front();
		curr_node = curr_glob->getNodePointer();
		if (curr_node->getLeftChild()!=0) {
			//get level, spread for left node and make a glob
			level = (curr_glob->getLevel())+2;
			spread = (curr_glob->getSpread())-2;
			Glob<T>* new_glob_left = new Glob<T>(*(curr_node->getLeftChild()), level, spread);
			q.push_back (new_glob_left);
			//insert left leg into tda
			tda->insert(level-1, spread_middle+spread+1, leftLeg);
		}
		if (curr_node->getRightChild()!=0) {
			level=(curr_glob->getLevel())+2;
			spread = (curr_glob->getSpread())+2;
			Glob<T>* new_glob_right = new Glob<T>(*(curr_node->getRightChild()), level, spread);
			q.push_back (new_glob_right);
			//insert right leg tda
			tda->insert(level-1, spread_middle+spread-1, rightLeg);			
		}		
		if (curr_node!=0) {
			l = curr_glob->getLevel();
			s = curr_glob->getSpread();
			tda->insert(l, spread_middle+s, curr_glob->getNodePointer()->getValue());
		}
		q.pop_front();	
	}
	tda->print();
	delete tda;
	delete root_glob;
}

template <typename T>
void AVLTree<T>::print() {
	traversalPrint(root);
}

template <typename T>
void AVLTree<T>::traversalPrint(Node<T>* n) {
	if(root != 0) {
		traversalPrint(n->getLeftChild());
		std::cout << n->getValue() << std::endl;
		traversalPrint(n->getRightChild());
	}
}

template <typename T>
void AVLTree<T>::postOrderTraversal() {
	cout << "Printing post-order traversal:" << endl;
	traversalPrintPost(root);
}

template <typename T>
void AVLTree<T>::traversalPrintPost(Node<T>* n) {
	if(n != 0) {
		traversalPrintPost(n->getLeftChild());
		traversalPrintPost(n->getRightChild());
		std::cout << "Value is " << n->getValue() << std::endl;
		std::cout << "Balance is " << n->getBalance() << endl;		
	}
}

template <typename T>
void AVLTree<T>::inOrderTraversal() {
	cout << "Printing in-order traversal with root: " << root->getValue() << endl;
	traversalPrintIn(root);
}

template <typename T>
void AVLTree<T>::traversalPrintIn(Node<T>* n) {
	if(n != 0) {
		traversalPrintIn(n->getLeftChild());		
		std::cout << "Value is " << n->getValue() << std::endl;
		std::cout << "Balance is " << n->getBalance() << endl;
		//cout << "It's address is " << n << endl;
		traversalPrintIn(n->getRightChild());
	}
}

template class AVLTree<int>;
template class AVLTree<double>;
template class AVLTree<std::string>;
