stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stack.o: stack.c stack.h
	gcc -g -c stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig5

clean:
	rm -f *.o
	rm -f stacktest
