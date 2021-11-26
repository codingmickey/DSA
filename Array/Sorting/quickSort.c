#include <stdio.h>

int count = 0;

// Pranit Sir's method with i and j starting from the start
int partition(int a[], int start, int end)
{
    int pivot = end, i = start, j = start;
    // then to run loop till i reaches the end-1 position
    while (i < end)
    {
        // if the current number is greater than the pivot do nothing. just i++;
        if (a[i] < a[pivot])
        {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j++;
        }
        i++;
        count++;
    }
    int temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;

    return j;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int p = partition(a, start, end);

        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("Sorted array(Quick Sort): ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("The final count is %d", count);

    return 0;
}