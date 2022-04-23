#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top;

void push(int val)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

int pop()
{
    int x;
    struct Node *temp = top;
    x = top->data;
    top = top->next;
    free(temp);
    return x;
}

void peek()
{
    printf("The top most element is %d\n", top->data);
}

void display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isFull()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Stack is FULL, Stack overflow!!");
        return 1;
    }
    else
    {
        free(temp);
        return 0;
    }
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    int choice = 0;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Push
            if (isFull())
            {
                printf("Stack is FULL, Stack overflow!!\n");
            }
            else
            {
                int val;
                printf("Enter a element to insert: ");
                scanf("%d", &val);
                push(val);
            }
            break;
        case 2:
            // Pop
            if (isEmpty())
            {
                printf("Stack is EMPTY, Stack underflow!!\n");
            }
            else
            {
                int val = pop();
                printf("The deleted value is %d\n", val);
            }
            break;
        case 3:
            // Peek
            if (isEmpty())
            {
                printf("Stack is EMPTY, Stack underflow!!\n");
            }
            else
            {
                peek();
            }
            break;
        case 4:
            // Display
            if (isEmpty())
            {
                printf("Stack is EMPTY, Stack underflow!!\n");
            }
            else
            {
                display();
            }
            break;

        case 5:
            break;
        default:
            printf("Enter a valid choice!!");
        }
    } while (choice != 5);

    return 0;
}