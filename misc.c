#include <stdio.h>
#include <stdlib.h>

typedef struct Node // created a used defined data type called Node
{
    int data;
    struct Node *next;
} Node;

void insert_At_End(Node *head, int data)
{
    Node *ptr, *temp;

    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
Node *insert_At_Beg(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

void insert_after(Node *head, int data, int item)
{
    Node *temp, *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->next = ptr->next;
            ptr->next = temp;
        }
        ptr = ptr->next;
    }
    printf("No such item present is present in the list");
}

void display(Node *head)
{

    if (head == NULL)
    {
        printf("List empty");
        return;
    }
    Node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    Node *head = NULL;
    head = insert_At_Beg(head, 10);
    insert_At_End(head, 20);
    display(head);
}