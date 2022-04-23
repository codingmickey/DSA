#include <stdio.h>
#define MAX 100

int top = -1;
int stack[MAX];

void push(int value)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
    }
}
void convert(int n)
{
    while (n != 0)
    {
        push(n % 2);
        n /= 2;
    }
}
void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Binary number: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d", stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int d;

    printf("Enter the decimal number: ");
    scanf("%d", &d);

    convert(d);
    display();

    return 0;
}