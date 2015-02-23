# CS2303 Homework 5
Homework 5 for WPI CS2303, by Arthur Lockman.

##Compiling
To compile the project, simply change into the project directory and type the following command in the terminal:

    make

To build the documentation into the public_html directory on CCC, type the following command into the terminal:

    make docs

To clean previous builds, type this command into the terminal:

    make clean

##Programs
This assignment contains 3 programs. Stacktest, queuetest, and nodetest. These are detailed below.

###stacktest
Stacktest demonstrates the performance of the stack system that was given to us as part of the homework assignment. It verifies that the push and pop order is correct and that the stack correctly handles overflow and underflow. Running this program produces output similar to what is shown below.

    user@system:~/CS2303-Homework-5$ ./stacktest
    Pushing: x =     6, y =     14.790
    Pushing: x =   217, y =      3.142
    Peeked:  x =   217, y =      3.142
    Popped:  x =   217, y =      3.142
    Popped:  x =     6, y =     14.790

    Verifying push and pop order.
    Pushed:  x =    34, y =     34.000
    Pushed:  x =  5023, y =     10.000
    Popped:  x =  5023, y =     10.000
    Order matches for new_foo4.
    Popped:  x =    34, y =     34.000
    Order matches for new_foo3.

    Verifying stack overflow condition.
    Pushed 1 elements, got return value 0.
    Pushed:  x =    34, y =     34.000
    Pushed 2 elements, got return value 0.
    Pushed:  x =    34, y =     34.000
    Pushed 3 elements, got return value 0.
    Pushed:  x =    34, y =     34.000
    Pushed 4 elements, got return value 0.
    Pushed:  x =    34, y =     34.000
    Pushed 5 elements, got return value 0.
    Pushed:  x =    34, y =     34.000
    Pushed 6 elements, got return value -1.
    Pushed:  x =    34, y =     34.000
    Got correct return value for overflow.
    Pushed 7 elements, got return value -1.
    Pushed:  x =    34, y =     34.000
    Got correct return value for overflow.

    Verifying stack underflow condition.
    Popped 1 elements, got return value 0x7f82fb404e90.
    Popped:  x =    34, y =     34.000
    Popped 2 elements, got return value 0x7f82fb404e90.
    Popped:  x =    34, y =     34.000
    Popped 3 elements, got return value 0x7f82fb404e90.
    Popped:  x =    34, y =     34.000
    Popped 4 elements, got return value 0x7f82fb404e90.
    Popped:  x =    34, y =     34.000
    Popped 5 elements, got return value 0x7f82fb404e90.
    Popped:  x =    34, y =     34.000
    Popped 6 elements, got return value 0x0.
    Got correct return value for underflow.
    Popped 7 elements, got return value 0x0.
    Got correct return value for underflow.

###queuetest
Queuetest demonstrates the performance of the queue system that we wrote as part of this assignment. It checks to see if the dequeue function returns the correct value for an empty queue, if the queue correctly handles overflow, if the queue can successfully empty itself, and if the dequeue order is correct. Running this program produces the output below. 

    user@system:~/CS2303-Homework-5$ ./queuetest
    Empty dequeue successfully returned null.
    Overflow correctly returned -1.
    Queue emptied successfully.
    New foo 1 dequeued in correct order.
    New foo 2 dequeued in correct order.
    New foo 3 dequeued in correct order.
    New foo 4 dequeued in correct order.

###nodetest
Nodetest verifies that the node insertion and sorting algorithm works properly. It creates a premade tree that sorts when inserting elements, and then prints it in descending order. It also creates a tree with random characters as the data points, which is also sorted on insertion, and prints that in descending order as well. Finally it frees all of the associated nodes. The output is randomized for the random tree, so the output will not look exactly as below but will be similar.

    user@system:~/CS2303-Homework-5$ ./nodetest
    Printing premade tree:
    Bob
    Gene
    Jimmy
    Linda
    Louise
    Mr. Frond
    Tina

    Printing random tree:
    BBJYWLSOGI
    BSQYTVJDNX
    BXDFGFHOBH
    CGZDYHQRZQ
    COBLTYXDYZ
    GDWICTUWQE
    GIQBUSRFBH
    GWWOVQKEJX
    JHVOUYQGOJ
    JTASZMJPUM
    JVELFUPEED
    KEYWTYOPDE
    LAXEZPZLPC
    PENGNZQEWC
    QGTCYCLRJP
    QMWMGGJAZU
    TJOAKLILYG
    TPKJJSQCIO
    TZLOJUPFYW
    XKYHPDRGJW
    ZCDXJLJAGX

    Freeing nodes...

