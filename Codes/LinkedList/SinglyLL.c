#include<stdio.h>
#include<stdlib.h>
// Creating a structure for node
struct node{
    // Normal integer vatable
    int data;

    // A pointer varible to store the address of Structure data type
    struct node *next;
};


// main

int main(){
    // Creating a pointer to the structure
    struct node *head;

    // Allocating Memory to the pointer variable
    head=(struct node*) malloc(sizeof(struct node));

    // Assining a value to structure variable
    head->data=100;

    // Saving Next address to NULL
    head->next=NULL;

    printf("Data at head: %d\n",head->data);
    printf("Memory Location of head : %u\n",&(head));
    printf("Memory Location of head->data : %u\n",&(head->data));
    printf("Memory Location of head->next : %u\n",&(head->next));
    return 0;
}