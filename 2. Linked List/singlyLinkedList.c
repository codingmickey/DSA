#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // 4
    struct Node *next; // 32 - 4
    // 64 - 8
};

struct Node *start, *temp;

void create()
{
    int n;
    struct Node *newnode;

    printf("Enter the number of nodes to create: ");
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

    if (start == NULL)
    {
        printf("Linkedlist is empty!\n");
        return;
    }

    temp = start;
    while (temp != NULL)
    {
        printf("\n%p\t%d", temp, temp->data);
        temp = temp->next;
    }
    printf("\n%ld %ld %ld\n", sizeof(struct Node), sizeof(int), sizeof(struct Node *));
}

void insert_after()
{
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
}

void insert_before()
{
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
}

void delete1()
{
    struct Node *prev;
    int x;

    printf("Enter the value to be deleted: ");
    scanf("%d", &x);

    temp = start;

    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
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
        case 6:
            printf("Bye..\n");
            break;

        default:
            printf("Enter a correct option!!\n");
            break;
        }
    } while (check != 6);
}