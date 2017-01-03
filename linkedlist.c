#include "linkedlist.h"

Linkedlist *linkedlist_create(){
    Linkedlist *list = (Linkedlist *)malloc(sizeof(Linkedlist));
    if(!list)
        return NULL;
    
    memset(list, 0, sizeof(Linkedlist));
    
    list->head = NULL;
    list->size = 0;
    
    return list;
}

void linkedlist_free(Linkedlist *list){
    if(list){
        
    }
}

int linkedlist_add(Linkedlist *list,Type add_data){
    if(!list)
        return ERROR;
    
    
    list->size++;
    
    return ERROR;
}

int linkedlist_remove_at_index(Linkedlist *list,int index){
    return ERROR;
}

int linkedlist_remove_element(Linkedlist *list,Type remove_item){
    return ERROR;
}

Type linkedlist_get_element(Linkedlist *list,int index){
    return NULL;
}
