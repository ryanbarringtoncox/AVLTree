#include "Node.h"
#include "Glob.h"
#include <string>
#include <iostream>
using std::endl;
using std::cout;
using std::string;


int main() {
	
	Node<int>* n1 = new Node<int>(5);
	Node<int>* n2 = new Node<int>(10);
	
	n2->setParent(*n1);
	cout << "Parent of n2 has value " << n2->getParent()->getValue() << endl;
	cout << "n2 has balance of " << n2->getBalance() << endl;
	n2->incBalance();
	cout << "n2 has balance of " << n2->getBalance() << endl;
	n2->decBalance(); 	n2->decBalance();
	cout << "n2 has balance of " << n2->getBalance() << endl;
	
	return 0;
}
