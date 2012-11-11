#include "AVLTree.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {
	
  AVLTree<std::string>* s = new AVLTree<std::string>();	

  s->insert("ccc");	
  s->insert("ggg");
  s->insert("aaa");
  s->insert("zzz");	
  s->insert("eee");
  s->insert("ddd");	
  s->preOrderTraversal();
		
  s->visualPrint("   ", " / ", " \\ ");
	
}
