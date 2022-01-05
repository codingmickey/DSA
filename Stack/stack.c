#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow(Stack is full)\nElement %d could not be inserted :(\n", value);
    }
    else
    {
        printf("%d inserted at the top of the stack.\n", value);
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("stack underflow\nEnter some elements before popping.");
        return 0;
    }
    else
    {
        int temp = stack[top];
        stack[top] = 0;
        top--;
        printf("Element %d was popped from the stack\n", temp);
        return temp;
    }
}

bool isFull()
{
    if (top == MAX_SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int peek()
{
    return stack[top];
}

void display()
{
    for (int i = top; i > -1; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int temp, value;

    do
    {
        printf("\nHelu there, this is mickey, welcome to the world of stacks ... \n      3-->     2-->\t\n");
        printf("\t|   |\t|   |\t|   |\n\t|   |\t|   |\t|   |\n\t|___|\t|___|\t|___|\n\t|___|\t|___|\t|_2_|\n\t|___|\t|_3_|\t|_3_|\n\n");
        printf("Various functions of the stack are given below: \n\n");
        printf("1. push - Enter the element to push into the stack\n");
        printf("2. pop - Remove the top element of the stack\n");
        printf("3. display - Display all elements of the stack\n");
        printf("4. isFull - Print whether the stack is full or not\n");
        printf("5. isEmpty - Print whether the stack is empty or not\n");
        printf("6. peek - Print the top most element of the stack\n\n");
        printf("Enter the corresponding number to run: ");

        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            printf("\nEnter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            value = pop();
            break;

        case 3:
            display();
            break;

        case 4:
            if (isFull())
                printf("\nThe stack is full!!\n");
            else
                printf("\nThe stack has some space remaning...\n");
            break;

        case 5:
            if (isEmpty())
                printf("The stack is empty!!\n");
            else
                printf("The stack is not empty...\n");
            break;

        case 6:
            value = peek();
            printf("The top most element of the stack is %d", value);
            break;

        default:
            printf("Enter proper number from the list.");
            break;
        }
        printf("\nDo you want to continue...?\nIf yes press 9: ");
        scanf("%d", &temp);
    } while (temp == 9);

    printf("\n\nThank you for playing along,\n\tMade with <3 by mickey\n");

    return 0;
}