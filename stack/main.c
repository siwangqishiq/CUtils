#include <stdio.h>
#include "stack.h"


int main(){
	Stack *stack = 	stack_create();

	for(int i=0;i<10;i++){
		stack_push(stack, i+1);
	}//end for i
	stack_print(stack);
	
	for(int i = 0; i< 5; i++){
		Type item;
		int code;
		
		code = stack_pop(stack,&item);
		if(code >= 0){
			printf("pop success = %d\n",item);
		}else{
			printf("pop Error!\n");
		}//endif
	}//end for i
	
	stack_push(stack, 777);

	stack_print(stack);

	Type item;
	stack_get(stack,&item);
	printf("pop success = %d\n",item);	

	stack_print(stack);
	
	stack_free(stack);

	printf("Run End!\n");
	return 0;
}
