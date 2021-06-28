
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int data;
	struct node* next;
};


struct node* head;

bool isEmpty = true;

int traverse(){
	if(isEmpty){
		printf("List is empty \n");
		return 0;
	}

	struct node* tempNode = head;

	while(tempNode !=NULL){
		printf("%d ---- ", tempNode->data);
		tempNode = tempNode->next;
	}
    printf("NULL\n");

	return 0;
}

int insertBeginning(){
	int n;

	struct node* current = (struct node*) malloc(sizeof(struct node));

	printf("Enter new element \n");
	scanf("%d",&n);

	if(isEmpty){
		current->next = NULL;
		current->data = n;
		head = current;
		isEmpty = false;
		return n;
	}
	
	current->next = head;
	current->data = n;
	head = current;
	return 0;
}


int main(){
	insertBeginning();
	insertBeginning();
	traverse();
	return 0;
}
