#include <stdio.h>

#define MAX 10
int queue[MAX];
int f = -1, r = -1;

void enque(int val)
{
    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r++;
    }
    queue[r] = val;
}

int deque()
{
}

int isFull()
{
    if (r == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (f == -1 || f > r)
        return 1;
    else
        return 0;
}

int main()
{
    int check;

    do
    {
        printf("1. Enque\n2. Deque\n3. Display\n4. Exit");
        printf("Enter your choice: ");
        scanf("%d", &check);

        switch (check)
        {
        case 1:
            // Enque
            if (isFull())
            {
                printf("Queue is FULL\n");
            }
            else
            {
                int val;
                printf("Enter a element to insert: ");
                scanf("%d", &val);
                enque(val);
            }
            break;
        case 2:
            // Pop
            if (isEmpty())
            {
                printf("Queue is EMPTY!\n");
            }
            else
            {
                int val = pop();
                printf("The deleted value is %d\n", val);
            }
            break;
        case 3:
            // Display
            if (isEmpty())
            {
                printf("Queue is EMPTY!\n");
            }
            else
            {
                display();
            }
            break;

        case 4:
            break;

        default:
            printf("Enter a correct option!!\n");
        }
    } while (check != 6);
    return 0;
}