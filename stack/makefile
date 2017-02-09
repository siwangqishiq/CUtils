run : build
	./run

build : main.o stack.o 
	gcc -o run main.o stack.o

main.o : main.c
	gcc -c main.c

stack.o : stack.h stack.c
	gcc -c stack.c 

clean:
	rm -f *.o run




