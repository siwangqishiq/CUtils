#include "arraylist.h"

//创建数组线性表
Arraylist *arraylist_create(int init_size){
    if(init_size <= 1)
        init_size = ARRAYLIST_INIT_SIZE;
    
    Arraylist *list = (Arraylist *)malloc(sizeof(Arraylist));
    if(!list)
        return NULL;
    
    memset(list,0,sizeof(Arraylist));
    list->total_size = init_size;
    list->size = 0;
    
    size_t len = list->total_size + 1;
    Type *data = (Type *)malloc(len * sizeof(Type));
    if(!data){
        free(list);
        return NULL;
    }
    memset(data,0,len * sizeof(Type));
    list->array = data;
    
    return list;
}

void arraylist_free(Arraylist *list){
    if(list){
        if(list->array){
            free(list->array);
            list->array = NULL;
        }
        
        free(list);
    }
}

void arraylist_print(Arraylist *list){
    if(!list)
        return;
    
    printf("[");
    for(int i = 0;i < list->size ;i++){
        int *d = (int *)list->array[i];
        printf("%d  ",*d);
    }//end for i
    printf("]\n");
}

int arraylist_add(Arraylist *list,Type add_data){
    if(!list)
        return ERROR;
    
    return arraylist_add_at_index(list, list->size, add_data);
}

int arraylist_scale_size(Arraylist *list,int scale_size){
    if(list->total_size >= scale_size)
        return ERROR;
    
    Type *new_array = (Type *)malloc(scale_size * sizeof(Type));
    if(!new_array)
        return ERROR;
    memset(new_array,0,scale_size * sizeof(Type));
    
    for(int i = 0;i<list->size;i++){
        new_array[i] = list->array[i];
    }//end for i
    free(list->array);
    
    list->array = new_array;
    list->total_size = scale_size;
    
    return OK;
}

//
int arraylist_add_at_index(Arraylist *list,int index,Type add_data){
    if(!list || index < 0)
        return ERROR;
    index = MIN(index, list->size);
    
    if(list->size + 1 >= list->total_size){//扩容
        arraylist_scale_size(list, 2 * list->total_size + 1);
    }
    
    //move element
    int i = list->size - 1;
    while(i >= index){
        list->array[i+1] = list->array[i];
        i--;
    }//end while
    
    list->array[index] = add_data;
    list->size++;
    
    return OK;
}

Type arraylist_get_element(Arraylist *list,int index){
    if(index < 0 || index >= list->size)
        return NULL;
    
    return list->array[index];
}

int arraylist_remove_at_index(Arraylist *list,int index){
    if(index < 0  || index >= list->size)
        return ERROR;
    
    //remove
    int last = list->size - 1;
    int i = index;
    while(i < last){
        list->array[i] = list->array[i + 1];
        i++;
    }//end while
    list->size--;
    
    return OK;
}

int arraylist_find_index(Arraylist *list,Type element){
    if(!list)
        return -1;
    
    int ret = -1;
    for(int i = 0;i < list->size;i++){
        if(arraylist_get_element(list, i) == element){
            ret = i;
            break;
        }
    }//end for i
    return ret;
}

int arraylist_remove_element(Arraylist *list,Type element){
    return arraylist_remove_at_index(list, arraylist_find_index(list, element));
}




