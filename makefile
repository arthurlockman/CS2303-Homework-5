all: stacktest queuetest nodetest randomnodetest

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

nodetest: nodetest.o node.o
	gcc -g nodetest.o node.o -o nodetest

randomnodetest: randomnodetest.o node.o
	gcc -g randomnodetest.o node.o -o randomnodetest

stack.o: stack.c stack.h
	gcc -g -c stack.c

queue.o: queue.c queue.h
	gcc -g -c queue.c

node.o: node.c node.h
	gcc -g -c node.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

randomnodetest.o: randomnodetest.c node.h
	gcc -g -c randomnodetest.c

nodetest.o: nodetest.c node.h
	gcc -g -c nodetest.c

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig5

clean:
	rm -f *.o
	rm -f stacktest 
	rm -f queuetest
	rm -f nodetest
