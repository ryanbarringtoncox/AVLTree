CPP = g++
CFLAGS = -Wall -Wextra -Werror

node_test: node_test.cpp Node.o
	$(CPP) $(CFLAGS) -o node_test $^

Node.o: Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp
	
clean:
	rm -f *.o;
	rm -f node_test;