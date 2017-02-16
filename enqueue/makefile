run : build
	./main

build : main.o enqueue.o
	gcc main.o enqueue.o -o main     

main.o : test_enqueue.c
	gcc -c test_enqueue.c -o main.o 

enqueue.o : enqueue.c enqueue.h
	gcc -c enqueue.c -o enqueue.o

clean : 
	rm *.o main

