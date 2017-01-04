#ifndef _linkedlist_h_
#define _linkedlist_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK         (0)
#define ERROR     (-1)


typedef void* Type;

struct _List_Node{
    Type *data;
    struct _List_Node *next;
    struct _List_Node *prior;
};

typedef struct _List_Node List_Node;

struct _Linkedlist{
    int size;
    List_Node *head;
};

typedef struct _Linkedlist Linkedlist;

Linkedlist *linkedlist_create();

void linkedlist_free(Linkedlist *list);

int linkedlist_add(Linkedlist *list,Type add_data);

int linkedlist_add_at_index(Linkedlist *list,int index,Type add_data);

int linkedlist_remove_at_index(Linkedlist *list,int index);

int linkedlist_remove_element(Linkedlist *list,Type remove_item);

Type linkedlist_get_element(Linkedlist *list,int index);

List_Node *linkedlist_create_list_node(Type data);

int linkedlist_remove_node(Linkedlist *list,List_Node *p);

#endif