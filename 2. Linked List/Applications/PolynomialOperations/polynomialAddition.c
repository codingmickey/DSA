#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int power, coeff;
    struct Node *next;
} * start1, *start2, *start3;

struct Node *create(struct Node *start)
{
    struct Node *newnode, *temp;
    int p = 9, c = 0;
    while (p != -1)
    {
        printf("Enter power: ");
        scanf("%d", &p);
        if (p != -1)
        {
            printf("Enter coefficient of x ^ %d: ", p);
            scanf("%d", &c);
            newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->power = p;
            newnode->coeff = c;
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
    return start;
}

struct Node *createAns(int p, int c)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->power = p;
    newnode->coeff = c;
    if (start3 == NULL)
    {
        start3 = newnode;
    }
    else
    {
        temp = start3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return start3;
}

void add()
{
    struct Node *temp1, *temp2;
    int p, c;
    temp1 = start1;
    temp2 = start2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->power > temp2->power)
        {
            p = temp1->power;
            c = temp1->coeff;
            temp1 = temp1->next;
        }
        else if (temp1->power < temp2->power)
        {
            p = temp2->power;
            c = temp2->coeff;
            temp2 = temp2->next;
        }
        else
        {
            p = temp1->power;
            c = temp1->coeff + temp2->coeff;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        start3 = createAns(p, c);
    }
    if (temp1 == NULL)
    {
        while (temp2 != NULL)
        {
            start3 = createAns(temp2->power, temp2->coeff);
            temp2 = temp2->next;
        }
    }
    else if (temp2 == NULL)
    {
        while (temp1 != NULL)
        {
            start3 = createAns(temp1->power, temp1->coeff);
            temp1 = temp1->next;
        }
    }
}

void display(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        if (temp->coeff > 0)
            printf("+%dx^%d ", temp->coeff, temp->power);
        else
            printf("%dx^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("For the 1st equation, enter the values(to quit enter power = -1)\n");
    start1 = create(start1);
    printf("For the 2nd equation, enter the values(to quit enter power = -1)\n");
    start2 = create(start2);
    add();
    printf("\nEqn1: ");
    display(start1);
    printf("\t+\n");
    printf("Eqn2: ");
    display(start2);
    printf("- - - - - - - - - - - - - -\n");
    printf("Ans: ");
    display(start3);

    return 0;
}