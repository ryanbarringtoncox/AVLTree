CPP = g++
CFLAGS = -Wall -Wextra -Werror

all: ttest

rotation_test: rotation_test.cpp AVLTree.cpp Node.o Glob.o TwoDArray.o
	$(CPP) $(CFLAGS) -o rotation_test $^

ttest: tree_test.cpp AVLTree.cpp Node.o Glob.o TwoDArray.o
	$(CPP) $(CFLAGS) -o ttest $^

AVLTree.o: AVLTree.h AVLTree.cpp
	$(CPP) $(CFLAGS) -c AVLTree.cpp

node_test: node_test.cpp Node.o
	$(CPP) $(CFLAGS) -o node_test $^

Node.o: Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp
	
Glob.o: Glob.h Glob.cpp
	$(CPP) $(CFLAGS) -c Glob.cpp
	
TwoDArray.o: TwoDArray.h TwoDArray.cpp
	$(CPP) $(CFLAGS) -c TwoDArray.cpp	
	
clean:
	rm -f *.o;
	rm -f node_test;
	rm -f rotation_test
	rm -f ttest
