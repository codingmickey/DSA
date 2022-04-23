#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i, j;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int x = a[i];
        a[i] = a[min];
        a[min] = x;
    }
}

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n = 50000;
    int a[n];
    srand(0);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    selectionSort(a, n);
    rvereseArray(a, 0, n - 1);
    clock_t t;
    t = clock();
    selectionSort(a, n);
    t = clock() - t;

    double time_taken = (double)t; // in seconds

    printf("insertionSort() took %f seconds to execute \n", time_taken);
    return 0;
}