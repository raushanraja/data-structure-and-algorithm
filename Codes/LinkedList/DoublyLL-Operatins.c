#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Creating LinkedList Structure
struct node
{
    int data;
    struct node *prev;
    struct node *next;

} * head;

// Operations
void traverse();
void insertAtBeginning();
void insertAtIntermediate();
void insertAtEnd();
void deleteAtBeginnig();
void deleteAtIntermediate();
void deleteAtEnd();

// Extra Varaible to manage List
bool isEmpty = true;
int count = 0;

int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        printf("\n0. Exit\n1. Traverse\n2. Insert At Beginning\n3. Insert at Intermediate Position\n4. Insert at End\n5. Delete at beginning\n6. Delete at Mid\n7. Delete at End\nEnter Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            traverse();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtIntermediate();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            deleteAtBeginnig();
            break;
        case 6:
            deleteAtIntermediate();
            break;
        case 7:
            deleteAtEnd();
            break;
        default:
            printf("\nEnter Correct Option\n");
            break;
        }
    } while (choice);
    return 0;
}

// Function definition
void traverse()
{
    struct node *current = head;
    if (!isEmpty)
    {
        while (current)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
        return 0;
    }

    printf("List is empty\n");
}

void insertAtBeginning()
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter new element ");
    scanf("%d", &newNode->data);
    if (isEmpty)
    {
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        isEmpty = false;
        count++;
        printf("\nNew List\n");
        traverse();
        return 0;
    }

    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    count++;
    printf("\nNew List\n");
    traverse();
}

void insertAtIntermediate()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    int n, i;
    printf("Enter position at which the element is to be added");
    scanf("%d", &n);
    if (n <= 1)
    {
        insertAtBeginning();
        return 0;
    }
    else if (n >= count - 1)
    {
        insertAtEnd();
        return 0;
    }
    printf("Enter new element ");
    scanf("%d", &newNode->data);
    for (i = 1; i < n; i++)
    {
        current = current->next;
    }

    newNode->prev = current->prev;
    current->prev->next = newNode;
    newNode->next = current;
    current->prev = newNode;
    count++;

    printf("\nNew List\n");
    traverse();
}

void insertAtEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    if (isEmpty)
    {
        insertAtBeginning();
        return 0;
    }

    printf("Enter new element ");
    scanf("%d", &newNode->data);
    while (current->next)
    {
        current = current->next;
    }

    newNode->prev = current;
    newNode->next = NULL;
    current->next = newNode;
    count++;

    printf("\nNew List\n");
    traverse();
}

void deleteAtBeginnig()
{

    struct node *temp = head;
    if (isEmpty)
    {
        printf("\nList is Empty\n");
        return 0;
    }
    head = head->next;
    printf("\nDeleted: %d\n", temp->data);
    traverse();
    if (!head)
    {
        isEmpty = true;
        printf("\nList is Empty\n");
        return 0;
    }
    head->prev = NULL;
    free(temp);
    count--;
    return 0;
}

void deleteAtIntermediate()
{
    struct node *current = head;
    struct node *temp;
    int n, i;
    if (isEmpty)
    {
        printf("\nList is Empty\n");
        return 0;
    }

    printf("Enter position to delete: ");
    scanf("%d", &n);
    if (n <= 1)
    {
        deleteAtBeginnig();
        return 0;
    }

    if (n >= count)
    {
        deleteAtEnd();
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        current = current->next;
    }
    temp = current;
    current->prev->next=current->next;
    current->next->prev=current->prev;
    count--;
    printf("\nDeleted: %d\n", temp->data);
    traverse();
    return 0;
}

void deleteAtEnd()
{

    struct node *current = head;
    struct node *temp;
    if (isEmpty)
    {
        printf("\nList is Empty\n");
        return 0;
    }
    while (current->next)
    {
        current = current->next;
    }
    temp = current;
    printf("\nDeleted: %d\n", temp->data);
    if (current == head)
    {
        isEmpty = true;
        head = NULL;
        traverse();
        return 0;
    }
    current = current->prev;
    current->next = NULL;
    count--;
    traverse();
}