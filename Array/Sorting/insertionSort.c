#include <stdio.h>

int insertionSort(int a[], int n)
{
    // Insertion Sort
    int counter = 0;
}

int main()
{
    int a[6] = {7, 3, 5, 6, 2, 1};
    int n = 6;

    int ans = insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}