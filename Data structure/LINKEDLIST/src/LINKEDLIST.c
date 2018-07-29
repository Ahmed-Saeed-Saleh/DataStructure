/*
 ============================================================================
 Name        : linkedlist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : linkedlist in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
  	  SIMPLY U NEDD TO MAKE A NODE OF STUCT AND POINTER
  	  SO
  	  WE MADE NODE OF STRUCT WHICH HOLD DATA AND  SELF REFENTIONL PINTER WHO IS POIT TO THE NEXT NODE
 *
 */
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insertAtFirst(int a){
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data=a;
	link->next = head;
	head=link;
}

void insertAtLast(int a){
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data=a;
	link->next=NULL;
	if(head==NULL){
		head=link;
		return;
	}
	struct node *curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=link;
}

void sizeOfList(void){
	int s=0;
	if(head==NULL){
		printf("The list is Empty\n");
		return;
	}
	s++;
	struct node *curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
		s++;
	}
	printf("The Size is %d\n",s);
}

void findItemInTheList(int a){
	int i=0;
	if(head==NULL){
		printf("the list is empty\n");
		return;
	}
	struct node *curr =head;
	i++;
	while(curr!=NULL){
		if(curr->data==a){
			printf("%d is found in %d position\n",a,i);
			return;
		}
		curr=curr->next;
		i++;
	}
	printf("%d is not found\n",a);
}

void updateItemInTheList(int old,int new){
	int pos=0;
	if(head==NULL){
		printf("The list is Empty\n");
		return;
	}
	struct node *curr=head;
	pos++;
	while(curr!=NULL){
		if(curr->data==old){
			curr->data=new;
			printf("the list is updated at %d\n",pos);
			return;
		}
		curr=curr->next;
		pos++;
	}
	printf("%d is not found in the list\n",old);
}

void printnode(void){
	if(head==NULL){
		printf("the list is empty\n");
		return;
	}
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

void removeNodeFromTheList(int data){
	int pos=0;
	struct node *delete_node;
	if(head==NULL){
		printf("the list is empty\n");
		return;
	}
	if(head->data==data){
		delete_node=head;
		head=head->next;
		printf("%d is deleted from the list at position %d\n",data,pos);
		free(delete_node);
		return;
	}
	struct node *curr=head->next;
	struct node *pre=head;
	pos++;
	while(curr!=NULL){
		if(curr->data==data){
			delete_node=curr;
			pre=curr->next;
			printf("%d is deleted from the list at position %d\n",data,pos);
			free(delete_node);
			return;
		}
		pre=curr;
		curr=curr->next;
	}
	printf("%d is not found in the list at any position\n",data);
}
int main(void){
	insertAtFirst(5);
	insertAtFirst(25);
	insertAtFirst(365);
	/////////////////////////////////////
	insertAtLast(60);
	insertAtLast(660);
	insertAtLast(6055);
	////////////////////////////////////
	printnode();
	/////////////////////////////////////
	sizeOfList();
	/////////////////////////////////////
	findItemInTheList(25);
	/////////////////////////////////////
	updateItemInTheList(60, 30);
	////////////////////////////////////
	printnode();
	/////////////////////////////////////
	removeNodeFromTheList(365);
	////////////////////////////////////
	printnode();
	return EXIT_SUCCESS;
}
