#include "AVLTree.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {

  AVLTree<std::string>* s = new AVLTree<std::string>();	

  //s->insert("ccc");	
  s->insert("ggg");
  s->insert("ppp");
  //s->insert("zzz");	
  s->insert("eee");
  s->insert("fff");
  s->insert("ddd");	
  s->insert("aaa");	
  s->inOrderTraversal();
  s->postOrderTraversal();
		
  s->visualPrint("   ", " / ", " \\ ");
  /*s->practiceRotation();
  s->visualPrint("   ", " / ", " \\ ");
	
  s->inOrderTraversal();
  s->postOrderTraversal();	
   */
	
}
