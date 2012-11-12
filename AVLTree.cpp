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
	
	//tree is empty, insert at root
	if (*curr == 0) {
		*curr = temp;			
	}
	
	else {

		//find the spot for new node
		Node<T>* parent;		
		while (*curr != 0) {
			if (v < (*curr)->getValue()) {
				parent = *curr;
				curr = &((*curr)->getLeftChild());
			} else if (v > (*curr)->getValue()) {
				parent = *curr;
				curr = &((*curr)->getRightChild());
			}
		}
		
		//set parent pointer
		temp->setParent(*parent);
		
		//insert the node
		*curr = temp;					

		Node<T>* child = temp;
		cn = 0;
		
		while (parent != 0) {

			//increment parent balance
			if (child->getValue() > parent->getValue()) parent->incBalance();
			else parent->decBalance();
			
			//critical node assignment
			if (cn == 0 && child->getBalance() == 2) {
				cout << child->getValue() << " is a CN!" << endl;
				cn = child;
			}
			
			//if parent is balanced break while loop no need to increment parental balance
			if (parent->getBalance() == 0) break;
			
			//cout << "Parent balance is " << parent->getBalance() << endl;
			parent=parent->getParent();
			child = child->getParent();
		}
		
		//special case: root is cn
		if (cn == 0 and root->getBalance() == 2) {
			cn = root;	
		}
		
		//if there is a cn do necessary rotations
		if (cn != 0) {
			
			if (cn->getBalance() == 2) {
				leftRotation(cn);
			}
			
		}
	}
}

template <typename T>
void AVLTree<T>::leftRotation(Node<T>* n) {
	cout << "leftRotation called with " << n->getValue() << endl;
	if (isRoot(n)) {
		cout << "And it's the root!" << endl;
		root = n;
		/*Node<T>* r = root;
		r->setBalance(0);
		r->setParent(r->*/
	}
	if (isRoot(n->getParent())) {
		cout << "Parent is root" << endl;
		Node<T>* p = cn->getParent();
		n->setParent(*(Node<T>*)(0));
		//n->setLeftChild(*p);
		root = n;
		root->decBalance();
		root->setLeftChild(*p);
	}
	
	//Node<T>* tempRC = cn->getRightChild();
	//Node<T>* tempLC = cn->getLeftChild();
	//nc->setLeftChild(parent);
	
	//cout << "Parent is " << p->getValue() << endl;
	//p->setParent(*n);
	//p = p->getRightChild();
	//cout << "Parent is " << p->getValue() << endl;
	//tempRC->setLeftChild(*n);
	//n->setRightChild(*tempLC);
	//n = tempRC;
	
	//don't forget to change balances!
}

template <typename T>
void AVLTree<T>::remove(T v) {
	Node<T>** curr =&root;
	
	//is v in tree?
	while(*curr!=0 && (*curr)->getValue()!= v) {
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
	TwoDArray<T>* tda = new TwoDArray<T>(14, 20, def);
	int spread_middle = 10;
	
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
void AVLTree<T>::preOrderTraversal() {
	cout << "Printing pre-order traversal:" << endl;
	traversalPrintPre(root);
}

template <typename T>
void AVLTree<T>::traversalPrint(Node<T>* root) {
	if(root != 0) {
		traversalPrint(root->getLeftChild());
		std::cout << root->getValue() << std::endl;
		traversalPrint(root->getRightChild());
	}
}

template <typename T>
void AVLTree<T>::traversalPrintPre(Node<T>* root) {
	if(root != 0) {
		std::cout << "Value is " << root->getValue() << std::endl;
		std::cout << "Balance is " << root->getBalance() << endl;
		traversalPrintPre(root->getLeftChild());
		traversalPrintPre(root->getRightChild());
	}
}

template class AVLTree<int>;
template class AVLTree<double>;
template class AVLTree<std::string>;
