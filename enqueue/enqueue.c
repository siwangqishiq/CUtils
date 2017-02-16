#include "enqueue.h"

Enqueue *enqueue_create(){
	Enqueue *queue = (Enqueue *)malloc(sizeof(Enqueue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return queue;
}

void enqueue_free(Enqueue *queue){
	if(!queue)
		return;
	
	Node *p = queue->head;
	Node *pp = NULL;
	while(p){
		pp = p;
		p = p->next;
		if(!pp){
			free(pp);
		}
	}//end while
	
	free(queue);
}

int enqueue_add(Enqueue *queue,Type data){
	if(!queue){
		printf("Queue is NULL\n");
		return QUEUE_ERROR;
	}
	
	Node *add_node = (Node *)malloc(sizeof(Node));
	if(!add_node){
		printf("Malloc Node Error\n");
		return QUEUE_ERROR;
	}
	
	memset(add_node,0,sizeof(Node));
	
	add_node->data = data;
	add_node->next = NULL;
	add_node->prior = NULL;

	Node *last_tail = queue->tail;
	if(last_tail){
		last_tail->next = add_node;
	}
	add_node->prior = last_tail;
	queue->tail = add_node;

	if(queue->size == 0){
		queue->head = queue->tail;
	}

	queue->size++;

	return QUEUE_OK;
}

int enqueue_remove(Enqueue *queue,Type *out){
	if(!queue){
		printf("Queue is NULL\n");
		return QUEUE_ERROR;
	}

	if(!queue->size){
		printf("Queue is empty\n");
		return QUEUE_ERROR;
	}
	
	Node *last_head = queue->head;
	if(!last_head){
		printf("Queue Occur Exceptions\n");
		return QUEUE_ERROR;
	}
	
	if(queue->head == queue->tail){
		queue->head = NULL;
		queue->tail = NULL;
	}else{
		Node *p = queue->head;
		p = p->next;
		if(p){
			p->prior = NULL;
		}
		
		queue->head = p;
	}
	
	if(out)
		*out = last_head->data;
	queue->size--;

	free(last_head);

	return QUEUE_OK;
}

int enqueue_get_head(Enqueue *queue,Type *out){
	if(!queue){
		printf("Queue is NULL\n");
		return QUEUE_ERROR;
	}
	
	if(queue->head){
		*out = queue->head->data;
	}		
	else{
		printf("Queue is empty no head\n");
		return QUEUE_ERROR;
	}
	
	return QUEUE_OK;
}

int enqueue_get_tail(Enqueue *queue,Type *out){
	if(!queue){
		printf("Queue is NULL\n");
		return QUEUE_ERROR;
	}

	if(queue->tail){
		*out = queue->tail->data;
	}else{
		printf("Queue is empty no tail\n");
		return QUEUE_ERROR;
	}
		
	return QUEUE_OK;
}



void enqueue_log(Enqueue *queue){
	if(!queue){
		printf("queue is NULL\n");
		return;
	}

	Node *p = queue->head;
	while(p){
		//printf("%d  ",p->data);
		p = p->next;
	}//end while

	printf("\nqueue size = %d\n",queue->size);
}
