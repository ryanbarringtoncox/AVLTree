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
	cout << endl;
	
	cout << "inserting iii, lll..." << endl;	
	s->insert("iii");
	s->insert("lll");	
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	cout << endl;
	
	cout << "inserting zzz..." << endl;	
	s->insert("zzz");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	cout << "inserting bbb, aaa..." << endl;	
	s->insert("bbb");
	s->insert("aaa");	
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	cout << endl;
	
	cout << "Removing aaa..." << endl;	
	s->remove("aaa");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	cout << endl;
	
	cout << "Removing ccc..." << endl;	
	s->remove("ccc");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();
	cout << endl;
	
	cout << "Removing zzz..." << endl;	
	s->remove("zzz");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	cout << "Inserting mmm, aaa, removing ggg..." << endl;
	s->insert("mmm");
	s->insert("aaa");
	s->remove("ggg");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	cout << "Removing aaa, bbb, ddd..." << endl;
	s->remove("aaa");
	s->remove("bbb");
	s->remove("ddd");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;

	cout << "Inserting zzz, rrr..." << endl;
	s->insert("zzz");
	s->insert("rrr");

	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	cout << "Removing mmm, zzz, rrr..." << endl;
	s->remove("mmm");
	s->remove("zzz");
	s->remove("rrr");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	cout << "inserting jjj..." << endl;	
	s->insert("jjj");
	
	s->visualPrint("   ", " / ", " \\ ");
	s->inOrderTraversal();	
	cout << endl;
	
	delete s;
}
