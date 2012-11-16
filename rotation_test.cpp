#include "AVLTree.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {

	AVLTree<std::string>* s = new AVLTree<std::string>();	

	cout << "inserting ggg, ddd, ccc..." << endl;
	s->insert("ggg");
	s->insert("ddd");	
	s->insert("ccc");		
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();

	cout << "inserting iii, lll..." << endl;	
	s->insert("iii");
	s->insert("lll");	
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();

	cout << "inserting zzz..." << endl;	
	s->insert("zzz");

	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	
	cout << "inserting bbb, aaa..." << endl;	
	s->insert("bbb");
	s->insert("aaa");	
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	
	cout << "Removing aaa..." << endl;	
	s->remove("aaa");

	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	
	cout << "Removing ccc..." << endl;	
	s->remove("ccc");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	
	cout << "Removing zzz..." << endl;	
	s->remove("zzz");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	
	
	cout << "Inserting mmm, aaa, removing ggg..." << endl;
	s->insert("mmm");
	s->insert("aaa");
	s->remove("ggg");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
}
