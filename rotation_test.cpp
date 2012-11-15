#include "AVLTree.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {

  AVLTree<std::string>* s = new AVLTree<std::string>();	

  s->insert("ggg");
  s->insert("ddd");	
  s->insert("ccc");		
	
  s->visualPrint("   ", " / ", " \\ ");
  s->inOrderTraversal();
	
  s->insert("iii");
  s->insert("lll");	
  //s->insert("rrr");	
	
  s->visualPrint("   ", " / ", " \\ ");
  s->inOrderTraversal();
	
  s->insert("zzz");

  s->visualPrint("   ", " / ", " \\ ");
  s->inOrderTraversal();	
	
  s->insert("bbb");
  s->insert("aaa");	
	
  s->visualPrint("   ", " / ", " \\ ");
  s->inOrderTraversal();	
	
}
