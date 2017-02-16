#include <stdio.h>
#include "enqueue.h"

typedef struct{
	char name[100];
	int age;
	char sex;
} Student;


void printStu(Student *stu){
	printf("name = %s, age = %d , sex = %c \n",stu->name,stu->age,stu->sex);
}

int main(){
	Enqueue *queue = enqueue_create();
	
	Student stu1;
	strcpy(stu1.name, "LiLei");
	stu1.age = 17;
	stu1.sex = 'f';

	Student stu2;
	strcpy(stu2.name, "HanMeiMei");
	stu2.age = 18;
	stu2.sex = 'm';

	Student stu3;
	strcpy(stu3.name, "Petter");
	stu3.age = 15;
	stu3.sex = 'f';
	
	enqueue_add(queue,&stu1);
	enqueue_add(queue,&stu2);
	enqueue_add(queue,&stu3);
	
	Student *pStu = NULL;
	enqueue_remove(queue, (void *)&pStu);
	printStu(pStu);

	enqueue_remove(queue, (void *)&pStu);
	printStu(pStu);

	enqueue_remove(queue, (void *)&pStu);
	printStu(pStu);

	enqueue_free(queue);
	return 0;
}
