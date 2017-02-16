#ifndef __ENQUEUE__
#define __ENQUEUE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Type;
//typedef int Type;

#define QUEUE_OK     0
#define QUEUE_ERROR -1

struct _Node{
	struct _Node *next;
	struct _Node *prior;
	Type data;
};

typedef struct _Node Node;

struct _Enqueue{
	int size;
	Node *head;
	Node *tail;
};

typedef struct _Enqueue Enqueue;

Enqueue *enqueue_create();

void enqueue_free(Enqueue *queue);

int enqueue_add(Enqueue *queue,Type data);

int enqueue_get_head(Enqueue *queue,Type *out);

int enqueue_get_tail(Enqueue *queue,Type *out);

int enqueue_remove(Enqueue *queue,Type *out);

void enqueue_log(Enqueue *queue);
#endif
