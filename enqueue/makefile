run : build
./

build : main.o enqueue.o
	gcc -o run main.o  

main.o : test_enqueue.o
	gcc  

enqueue.o : enqueue.h
	gcc -c enqueue.c -o enqueue.o

