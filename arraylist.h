#ifndef _arraylist_h_
#define _arraylist_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYLIST_INIT_SIZE      10

#define OK                        0
#define ERROR                    -1

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef void* Type;

struct _Arraylist{
    Type *array;
    
    int total_size;
    int size;
};

typedef struct _Arraylist Arraylist;

Arraylist *arraylist_create(int init_size);

void arraylist_free(Arraylist *list);

void arraylist_print(Arraylist *list);

int arraylist_add(Arraylist *list,Type add_data);

int arraylist_scale_size(Arraylist *list,int scale_size);

int arraylist_add_at_index(Arraylist *list,int index,Type add_data);

Type arraylist_get_element(Arraylist *list,int index);

int arraylist_remove_at_index(Arraylist *list,int index);

int arraylist_remove_element(Arraylist *list,Type element);

int arraylist_find_index(Arraylist *list,Type element);

#endif