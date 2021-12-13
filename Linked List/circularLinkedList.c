#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start, *last, *temp;

void create()
{
    int n, val;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    struct Node *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data to insert: ");
        scanf("%d", &val);
        newnode->data = val;

        if (start == NULL)
        {
            start = newnode;
            newnode->next = start;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->next = start;
            last = newnode;
        }
    }
}

void display()
{
    if (start == NULL)
    {
        printf("Linked list is not present!\n");
        return;
    }

    temp = start;
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void insert_after()
{
    printf("Values in the nodes: \n");
    display();

    struct Node *newnode;
    int val, x;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data to insert: ");
    scanf("%d", &val);
    newnode->data = val;
    printf("Enter after which node to insert: ");
    scanf("%d", &x);

    temp = start;
    while (temp->data != x)
    {
        temp = temp->next;
    }

    if (temp == last)
    {
        last = newnode;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_before()
{
    printf("Values in the nodes: \n");
    display();

    struct Node *newnode, *prev;
    int val, x;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data to insert: ");
    scanf("%d", &val);
    newnode->data = val;
    printf("Enter before which node to insert: ");
    scanf("%d", &x);

    temp = start;
    while (temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == start)
    {
        newnode->next = start;
        start = newnode;
        last->next = start;
    }
    else
    {
        newnode->next = prev->next;
        prev->next = newnode;
    }
}

void delete1()
{
    printf("Values in the nodes: \n");
    display();

    struct Node *newnode, *prev;
    int x;

    printf("Enter the which node to delete: ");
    scanf("%d", &x);

    temp = start;
    if (temp->data == x)
    {
        start = temp->next;
        last->next = start;
        free(temp);
    }
    else
    {
        while (temp->next != start && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == start && temp->data != x)
        {
            printf("Node not found!\n");
        }
        else if (temp == last)
        {
            prev->next = start;
            last = prev;
            free(temp);
        }
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

int main()
{
    int check;
    do
    {
        printf("\nCircular Linked list\n");
        printf("1 - Create\n");
        printf("2 - Display\n");
        printf("3 - Insert After\n");
        printf("4 - Insert Before\n");
        printf("5 - Delete\n");
        printf("6 - Exit\n\n");
        printf("Enter a choice: ");
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
            printf("Bye..");
            break;
        default:
            printf("Enter a PROPER choice!!");
        }
    } while (check != 6);

    return 0;
}