#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *temp;

void create()
{
    struct Node *newnode;

    int n;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void display()
{
    temp = start;

    while (temp != NULL)
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_after()
{
    printf("Data in the nodes are: \n");
    display();

    struct Node *newnode;
    int x, val;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    newnode->data = val;

    printf("Enter the node after which you want to insert: ");
    scanf("%d", &x);

    temp = start;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    printf("Data in the nodes after inserting %d after %d is: \n", val, x);
    display();
}

void insert_before()
{
    printf("Data in the nodes are: \n");
    display();

    struct Node *newnode, *prev;
    int x, val;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    newnode->data = val;

    printf("Enter the node before which you want to insert: ");
    scanf("%d", &x);

    temp = start;
    while (temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == start)
    {
        newnode->next = temp;
        start = newnode;
    }
    else
    {
        prev->next = newnode;
        newnode->next = temp;
    }

    printf("Data in the nodes after inserting %d before %d is: \n", val, x);
    display();
}

void delete1()
{
    printf("Data in the nodes are: \n");
    display();

    struct Node *prev;
    int x;

    printf("Enter the value to be deleted: ");
    scanf("%d", &x);

    temp = start;
    prev = start;

    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!");
        return;
    }
    else if (temp == start)
    {
        start = temp->next;
        free(temp);
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }

    printf("Data in the nodes after deleting %d is: \n", x);
    display();
}

int main()
{
    int check;

    do
    {
        printf("\n------LinkedList Operations------\n");
        printf("1 --> create(), Create a linkedlist with n nodes\n");
        printf("2 --> display(),  Display all nodes\n");
        printf("3 --> insert_after(), Insert after a Node\n");
        printf("4 --> insert_before(), Insert before a Node\n");
        printf("5 --> delete(), Delete a node\n");
        printf("6 --> Exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &check);

        switch (check)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            insert_before();
            break;
        case 5:
            delete1();
            break;

        default:
            printf("Enter a correct option!!");
            break;
        }
    } while (check != 6);
}