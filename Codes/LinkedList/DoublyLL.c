#include <stdio.h>
#include <stdlib.h>

// Creating a structure for Doubly Linked List
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head;

// Main
int main(int argc, char const *argv[])
{
    // Creating a nodes for storing data
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));

    // For traversing
    struct node *current;

    //   Adding data and pointers to node 1
    node1->data = 100;
    node1->prev = NULL;
    node1->next = node2;

    // Adding data and pointer to node 2
    node2->data = 200;
    node2->prev = node1;
    node2->next = NULL;

    // Pointing head to node 1
    head=node1;
    current=head;

    //Traversing
    while (current)
    {
        printf("|%u | %d |%u | -> ",current->prev,current->data,current->next);
        current=current->next;
    }
    printf("\n");

    return 0;
}
