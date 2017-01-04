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
        List_Node *p = list->head;
        while(p){
            List_Node *t_prior = p;
            p = p->next;
            if(t_prior)
                free(t_prior);
            t_prior = NULL;
        }//end while
        
        free(list);
    }
}

int linkedlist_add(Linkedlist *list,Type add_data){
    return linkedlist_add_at_index(list,list->size,add_data);
}

int linkedlist_add_at_index(Linkedlist *list,int index,Type add_data){
    if(!list || index < 0 || !add_data)
        return ERROR;
    
    List_Node *node = linkedlist_create_list_node(add_data);
    if(!node)
        return ERROR;
    
    if(index == 0 || list->size == 0){//insert to the head
        List_Node *p = list->head;
        list->head = node;
        list->head->next = p;
        list->head->prior = NULL;
        
        if(p)
            p->prior = list->head;
    }else{//insert to the other
        if(index >= list->size)
            index = list->size;
        
        List_Node *p = list->head;
        List_Node *prior_node = NULL;
        int count = 0;
        while(count < index && p){
            count++;
            
            if(!p->next)
                prior_node = p;
             p = p->next;
        }//end while
        
        if(p)
            prior_node = p->prior;
        
        List_Node *next_node = p;
        
        if(prior_node){
            prior_node->next = node;
            node->prior = prior_node;
        }
        
        if(next_node){
            node->next = next_node;
            next_node->prior = node;
        }
        
    }//end if
    
    list->size++;
    
    return OK;
}

int linkedlist_remove_node(Linkedlist *list,List_Node *p){
    if(!p)
        return ERROR;
    
    if(p->prior){//有前缀
        List_Node *prior_node = p->prior;
        List_Node *next_node = p->next;
        prior_node->next = next_node;
        if(next_node){
            next_node->prior = prior_node;
        }
    }else{//无前缀
        list->head = p->next;
        if(list->head)
            list->head->prior = NULL;
    }
    
    free(p);
    list->size--;
    
    return OK;
}

int linkedlist_remove_at_index(Linkedlist *list,int index){
    if(!list || index < 0 || index >= list->size)
        return ERROR;
    
    List_Node *p = list->head;
    int count = 0;
    while(p && count < index){
        p = p->next;
        count++;
    }//end while
    
    return linkedlist_remove_node(list, p);
}

int linkedlist_remove_element(Linkedlist *list,Type remove_item){
    if(!list || !remove_item)
        return ERROR;
    
    List_Node *p = list->head;
    while(p){
        if(p->data == remove_item)
            break;
        p = p->next;
    }//end while
    
    return linkedlist_remove_node(list, p);
}

Type linkedlist_get_element(Linkedlist *list,int index){
    if(!list || index < 0)
        return NULL;
    
    List_Node *p = list->head;
    int count = 0;
    while(p && count < index){
        p = p->next;
        count++;
    }//end while
    
    return p?p->data:NULL;
}

//----- private function--------
List_Node *linkedlist_create_list_node(Type data){
    List_Node *node = (List_Node *)malloc(sizeof(List_Node));
    if(!node)
        return NULL;
    memset(node, 0, sizeof(List_Node));
    node->data = data;
    
    return node;
}

