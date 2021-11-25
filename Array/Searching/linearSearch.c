#include <stdio.h>

int linearSearch(int a[], int x, int n)
{
    // Linear Search
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int x, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter a number to be found: ");
    scanf("%d", &x);

    int ans = linearSearch(a, x, n);

    if (ans == -1)
    {
        printf("Element not found!");
    }
    else
    {
        printf("Element found at index %d", ans);
    }

    return 0;
}