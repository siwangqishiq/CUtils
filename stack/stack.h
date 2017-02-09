#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

//typedef void* Type;
typedef int Type;

struct _Node{
	Type data;
	struct _Node *next;
};

typedef struct _Node Node;

typedef struct{
	Node *head;
	int size;
} Stack;


Stack *stack_create();

void stack_free(Stack *stack);

void stack_print(Stack *stack);

int stack_push(Stack *stack,Type item);

int stack_pop(Stack *stack,Type *out);

int stack_get(Stack *stack,Type *out);

#endif
