#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front, *rear;

void enque(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
int deque()
{
    struct Node *temp = front;
    int tempVal = front->data;
    front = front->next;
    free(temp);
    return tempVal;
}

void display()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void element(char x)
{
    printf("The element at %s is %d\n", (x == 'f' ? "front" : "back"), (x == 'f' ? front->data : rear->data));
}

int isFull()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
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
    if (front == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Enque\n2. Deque\n3. Display\n4. Element at Front\n5. Element at Back\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Enque
            if (isFull())
            {
                printf("Queue is FULL!\n");
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
            // Deque
            if (isEmpty())
            {
                printf("Queue is EMPTY!\n");
            }
            else
            {
                int val = deque();
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
            // Element at Front
            if (isEmpty())
            {
                printf("Queue is EMPTY!\n");
            }
            else
            {
                element('f');
            }
            break;
        case 5:
            // Element at Back
            if (isEmpty())
            {
                printf("Queue is EMPTY!\n");
            }
            else
            {
                element('b');
            }
            break;

        case 6:
            break;
        default:
            printf("Enter a valid choice!!");
        }
    } while (choice != 6);

    return 0;
}