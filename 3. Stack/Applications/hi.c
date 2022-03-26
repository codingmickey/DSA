#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("The stack is full, STACK OVERFLOW\n");
        return;
    }
    top++;
    stack[top] = x;
}

char pop()
{
    if (top == -1)
    {
        printf("The stack is empty, STACK UNDERFLOW\n");
        return 0;
    }
    char temp = stack[top];
    stack[top] = 0;
    top--;
    return temp;
}

int priority(char a)
{
    switch (a)
    {
    case '^':
        return 3;

    case '%':
    case '/':
    case '*':
        return 2;

    case '-':
    case '+':
        return 1;

    case '(':
        return 0;

    default:
        break;
    }
}

int main()
{
    char infix[MAX];

    int temp = 0;

    printf("\nEnter the infix expression: ");
    scanf("%s", &infix);

    char postfix[strlen(infix)];

    int i = 0;
    while (infix[i] != '\0')
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix[temp] = infix[i];
            temp++;
        }
        else if (infix[i] == '(')
        {
            push('(');
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[temp] = pop();
                temp++;
            }
            pop();
        }
        else
        {
            if (top == -1)
            {
                push(infix[i]);
            }
            else
            {
                if (priority(infix[i]) <= priority(stack[top]))
                {
                    while (priority(infix[i]) <= priority(stack[top]))
                    {
                        postfix[temp] = pop();
                        temp++;
                    }
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while (top != -1)
    {
        postfix[temp] = pop();
        temp++;
    }
    i = 0;
    printf("\nPostfix expression: ");
    while (i != temp)
    {
        printf("%c", postfix[i]);
        i++;
    }
    printf("\n");

    return 0;
}