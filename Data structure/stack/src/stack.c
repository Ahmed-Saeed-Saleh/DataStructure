/*
 ============================================================================
 Name        : STACK.c
 Author      : Ahmed Saeed
 Copyright   : Your copyright notice
 Description : STACK in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int a){
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

void pop(void){
	struct node *delete_node;
	struct node *prev;
	if(top==NULL){
		printf("The Stact is empty \n");
		return;
	}
	if(top->next==NULL){
		delete_node=top;
		top=top->next;
		free(delete_node);
		return;
	}
	delete_node=top;
	while(delete_node->next!=NULL){
		prev=delete_node;
		delete_node=delete_node->next;
	}
	prev->next=NULL;
	free(delete_node);
}
void sizeOfStack(void){
	int s=0;
	if(top==NULL){
		printf("The Stack is empty \n");
		return;
	}
	struct node *curr=top;
	s++;
	while(curr->next!=NULL){
		curr=curr->next;
		s++;
	}
	printf("The Stack Size  is %d\n",s);
}
void print(void){
	struct node *ptr ;
	if(top==NULL){
		printf("the stack is empty\n");
		return;
	}
	ptr=top;
	while(ptr!=NULL){
		printf("%d \n",ptr->data);
		ptr=ptr->next;
	}
}
int main(void) {
	push(5);
	push(6);
	push(95);
	push(15);
	//////////////////////////////////
	sizeOfStack();
	//////////////////////////////////
	print();
	//////////////////////////////////
	pop();
	//////////////////////////////////
	print();
	//////////////////////////////////
	pop();
	pop();
	//////////////////////////////////
	sizeOfStack();
	pop();
	//////////////////////////////////
	print();
	return EXIT_SUCCESS;
}
