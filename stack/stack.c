#include "stack.h"

Stack *stack_create(){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(!stack){
		printf("ERROR malloc stack failed!\n");
		return NULL;
	}
	
	stack->head = NULL;
	stack->size = 0;

	return stack;
}

void stack_free(Stack *stack){
	if(!stack) return;
	
	if(stack->head){
		Node *p = stack->head;
		while(p){
			Node *q = p;
			p = p->next;
			if(q){
				free(q);
			}
		}		
	}
	
	free(stack);
}

void stack_print(Stack *stack){
	if(!stack) return;

	Node *p = stack->head;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}//end while
	printf("\n");
	
	printf("stack size = %d\n",stack->size);
}

int stack_push(Stack *stack,Type item){
	if(!stack) return -1;
	 Node *origin_head = stack->head;

	Node *node = (Node *)malloc(sizeof(Node));
	if(!node){
		printf("ERROR malloc Node failed\n");
		return -1;
	}
	node->data = item;

	stack->head = node;
	node->next = origin_head;

	stack->size++;
	return 0;
}

int stack_pop(Stack *stack,Type *out){
	if(!stack) return -1;
	if(stack->size <= 0 || !stack->head)
		return -1;

	Node *p = stack->head;
	stack->head = p->next;
	*out = p->data;
	stack->size--;	
	
	if(p)
		free(p);
	
	return 0;
}

int stack_get(Stack *stack,Type *out){
	if(!stack) return -1;
	if(stack->size <= 0 || !stack->head)
		return -1;

	*out = stack->head->data;
	return 0;
}




