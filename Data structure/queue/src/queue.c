/*
 ============================================================================
 Name        : queue.c
 Author      : Ahmed Saeed
 Copyright   : Your copyright notice
 Description : queue in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void queue(int a){
	struct node *link =(struct node *)malloc(sizeof(struct node )) ;
	link->data=a;
	link->next=NULL;
	if(top==NULL){
		top=link;
		return;
	}
	struct node *curr =top;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=link;
}

void dequeue(void){
	struct node *delete_node;
	if(top==NULL){
		printf("THE Queue is empty \n");
		return;
	}
	delete_node=top;
	top=top->next;
	free(delete_node);
}
void sizeOfQueue(void){
	int s=0;
	if(top==NULL){
		printf("The queue is empty \n");
		return;
	}
	struct node *curr=top;
	s++;
	while(curr->next!=NULL){
		curr=curr->next;
		s++;
	}
	printf("The queue Size  is %d\n",s);
}
void print(void){
	struct node *ptr ;
	if(top==NULL){
		printf("the queue is empty\n");
		return;
	}
	ptr=top;
	while(ptr!=NULL){
		printf("%d \n",ptr->data);
		ptr=ptr->next;
	}
}
int main(void) {
	queue(5);
	queue(90);
	queue(30);

	sizeOfQueue();

	print();

	dequeue();

	print();

	sizeOfQueue();

	dequeue();

	print();
	return EXIT_SUCCESS;
}
