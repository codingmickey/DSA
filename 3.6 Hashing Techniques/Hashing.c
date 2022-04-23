// NOT MY CODE
#include <stdio.h>
#define m 10
int h[m], i, k, flag = 0;

void insert()
{
    int val;
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    k = val % m;
    if (h[k] == -1)
    {
        h[k] = val;
        flag = 1;
    }
    else
    {
        for (i = 1; i < m; i++)
        {
            k = ((val % m) + i) % m;
            if (h[k] == -1)
            {
                h[k] = val;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Hash Table Full\n");
        flag = 0;
    }
}

void delete ()
{
    int val;
    printf("Enter value to be deleted: ");
    scanf("%d", &val);
    k = (val % m);
    if (h[k] == val)
    {
        h[k] = -1;
        flag = 1;
    }
    else
    {
        for (i = 1; i < m; i++)
        {
            k = ((val % m) + i) % m;
            if (h[k] == val)
            {
                h[k] = -1;
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        printf("Value not present in Hash Table\n");
        flag = 0;
    }
}

void search()
{
    int val, pos;
    printf("Enter value to be searched: ");
    scanf("%d", &val);
    k = val % m;
    if (h[k] == val)
    {
        flag = 1;
        pos = k;
    }
    else
    {
        for (i = 1; i < m; i++)
        {
            k = ((val % m) + i) % m;
            if (h[k] == val)
            {
                flag = 1;
                pos = i;
            }
        }
    }
    if (flag == 0)
    {
        printf("Value not found\n");
        flag = 0;
    }
    else
    {
        printf("Value found at position %d\n", pos);
        flag = 0;
    }
}

void display()
{
    printf("Hash Table:\t");
    for (i = 0; i < m; i++)
        printf("%d\t", h[i]);
    printf("\n");
}
void main()
{
    for (i = 0; i < m; i++)
        h[i] = -1;
    int choice;
    printf("MENU\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        }
    } while (choice < 5);
}