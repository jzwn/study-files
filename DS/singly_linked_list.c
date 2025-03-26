#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
	newNode ->data=data;
	newNode-> next=NULL;
	return newNode;
}

void insertAtFirst(struct Node** head, int data)
{
	struct Node* newNode=createNode(data);
	newNode->next= *head;
	*head = newNode;
}

void insertAtEnd(struct Node** head, int data
