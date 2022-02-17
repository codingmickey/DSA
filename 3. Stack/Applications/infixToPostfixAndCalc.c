#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int calcS[MAX_SIZE];
int top = -1;

void push(char x)
{
    if (top == MAX_SIZE - 1)
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

void pushi(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("The stack is full, STACK OVERFLOW\n");
        return;
    }
    top++;
    stack[top] = x;
}

int popi()
{
    if (top == -1)
    {
        printf("The stack is empty, STACK UNDERFLOW\n");
        return 0;
    }
    int temp = stack[top];
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

int calc(char postfix[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\ni:%c", postfix[i]);
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int op1 = popi();
            int op2 = popi();
            printf("\nop1:%d\top2:%d\n", op1, op2);
            int ans;
            switch (postfix[i])
            {
            case '+':
                ans = op2 + op1;
                break;
            case '-':
                ans = op2 - op1;
                break;
            case '*':
                ans = op2 * op1;
                break;
            case '/':
                ans = op2 / op1;
                break;
            }
            push(ans);
        }
        else
        {
            pushi(postfix[i] - '0');
        }
    }

    return pop();
}

int main()
{
    char infix[MAX_SIZE];

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
    printf("\n\nThe value of the expression is %d", calc(postfix, temp));

    return 0;
}