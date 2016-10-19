#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"


#define MAX_STRING_LEN  100
typedef struct _MyData
{
	char name[MAX_STRING_LEN];
	float height;
	int age;
	char hobby[MAX_STRING_LEN];
} MyData;

void print(MyData *stu);

int main()
{
	map_t map = hashmap_new();
	
	MyData *stu1 = (MyData *)malloc(sizeof(MyData));
	strcpy(stu1->name, "新一");
	stu1->height = 1.7f;
	stu1->age = 17;
	strcpy(stu1->hobby, "毛利兰");

	MyData *stu2 = (MyData *)malloc(sizeof(MyData));
	strcpy(stu2->name, "鲁路修");
	stu2->height = 1.6f;
	stu2->age = 17;
	strcpy(stu2->hobby, "夏利");

	MyData *stu3 = (MyData *)malloc(sizeof(MyData));
	strcpy(stu3->name, "夜神月");
	strcpy(stu3->hobby, "无");
	stu3->height = 1.6f;
	stu3->age = 17;

	hashmap_put(map,stu1->name,stu1);
	hashmap_put(map,stu2->name,stu2);
	hashmap_put(map,stu3->name,stu3);
	
	MyData *value = NULL;
	hashmap_get(map,"新一",(void **)&value);

	if(value != NULL)
	{
		//print(value);
	}

	hashmap_remove(map,"新一");

	hashmap_get(map,"新一",(void **)&value);

	if(value != NULL)
	{
		print(value);
	}

	free(stu1);
	free(stu2);
	free(stu3);
	
	hashmap_free(map);
	printf("-----end --------\n");
	return 1;
}

void print(MyData *stu)
{
	printf("name : %s\n",stu->name);
	printf("hobby : %s\n",stu->hobby);
	printf("height : %1.2f\n",stu->height);
	printf("age : %d\n",stu->age);
}