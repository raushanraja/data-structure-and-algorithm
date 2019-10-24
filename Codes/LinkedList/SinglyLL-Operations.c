#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Creating structure
struct node
{
    int data;
    struct node *next;
} * head;

// Keeping track if List is empty or not
bool isEmpty = true;
// Keeping count of elements
int count;

// Operations
// Traversing List
void traverse();

// Insertion
// Insert At Beginning
int insertAtBeginning();
// Insert At Middle
int insertAtMiddle();
// Insert At End
int insertAtEnd();

// Deletion
// Delete At Beginning
int deleteAtBeginning();
// Delete At Middle
int deleteAtMiddle();
// Delete At End
int deleteAtEnd();

// Main
int main()
{
    int choice;
    do
    {
        printf("1. Traverse\n2. Insert At Beginnig\n3. Insert At Middle\n4. Insert At End\n5. Delete At Beginnig\n6. Delete At Middle\n7. Delete At End\n8.Exit\nEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtMiddle();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtMiddle();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            printf("\nExiting Program\n");
            return 0;
            break;
        default:
            printf("Select correct option\n");
            break;
        }
    } while (choice != 8);

    return 0;
}

// Function Definition

// Traversing
void traverse()
{
    // Creating current pointer and initializing it to head
    struct node *current = head;

    // Check if list is empty or not, if not empty then traverse
    if (!isEmpty)
    {
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n\n");
    }
    else
    {
        printf("\nList is Empty\n");
    }
}

// Insertion
int insertAtBeginning()
{
    // Variable for input new data
    int n;

    // Creating a new node
    struct node *current = (struct node *)malloc(sizeof(struct node));

    // Input to console
    printf("Enter the number to add:");
    scanf("%d", &n);

    if (isEmpty)
    {
        // Adding the input to new node
        current->data = n;

        // Setting next pointer of current node to NULL
        current->next = NULL;

        // Setting next pointer of head node to new node address
        head = current;

        // Setting isEmpty to false
        isEmpty = false;

        // Increasing count of element
        count++;

        // Printing Inserted data and new list
        printf("%d Inserted at beginnig\n New List: \t", n);
        traverse();
    }
    // Checking if new node is allocated memory
    else if (current)
    {
        current->data = n;
        current->next = head;
        head = current;
        count++;
        // Printing Inserted data and new list
        printf("%d Inserted at beginnig\nNew List:", n);
        traverse();
    }
    else
    {
        printf("No space available\n");
    }

    return 0;
}

int insertAtMiddle()
{

    // Creating new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    int i = 1, n;
    printf("Enter position after which new data will be added:");
    scanf("%d", &n);

    // If n is 0, insert at beginning
    if (n == 0)
    {
        insertAtBeginning();
        return 0;
    }

    // If n is larger than total element, insert at end
    if (n > count)
    {
        insertAtEnd();
        return 0;
    }

    // Getting to position where new element is to added
    for (i; i < n; i++)
    {
        current = current->next;
    }

    printf("Enter new data:");
    scanf("%d", &temp->data);
    temp->next = current->next;
    current->next = temp;
    count++;

    traverse();
}

int insertAtEnd()
{
    struct node *current = head;

    // Creating a new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (isEmpty)
    {
        insertAtBeginning();
        return 0;
    }

    // Reaching last node
    while (current->next != NULL)
    {
        current = current->next;
    }

    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    current->next = temp;
    count++;

    traverse();
    return 0;
}

// Deletion
int deleteAtBeginning()
{
    struct node *temp = head;
    if (!isEmpty)
    {
        printf("Deleted: %d\n", head->data);
        if (head->next)
        {
            head = head->next;
            return 0;
        }

        isEmpty = true;
        head = head->next;
        printf("List is empty\n");
        count--;
    }
    else
    {
        printf("List is empty\n");
    }
    return 0;
}

int deleteAtMiddle()
{
    int n, i = 1;
    struct node *temp = head;
    if (!isEmpty)
    {
        printf("Enter the postition after which element is to be deleted:");
        scanf("%d", &n);
        if (n <= 1)
        {
            deleteAtBeginning();
            return 0;
        }
        else if (n >= count - 1)
        {
            deleteAtEnd();
        }
        else
        {
            for (i = 1; i < n; i++)
            {
                temp = temp->next;
            }
            printf("Deleted :%d\n", temp->next->data);
            temp->next = temp->next->next;
            count--;
        }
    }
    else
    {
        printf("List is Empty\n");
    }

    return 0;
}

int deleteAtEnd()
{
    struct node *temp = head;
    struct node *temp2 = head;
    if (!isEmpty)
    {
        if (temp->next)
        {
            while (temp->next && !isEmpty)
            {
                temp2 = temp;
                temp = temp->next;
            }
            printf("Deleted: %d \n", temp->data);
            temp2->next = NULL;
            count--;
        }
        else
        {
            isEmpty = true;
            printf("Deleted: %d \n", temp->data);
            head = NULL;
            count = 0;
        }
    }
    else
    {
        printf("List is empty\n");
    }
    return 0;
}
