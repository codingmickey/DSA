#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    insertionSort(a, n);
    rvereseArray(a, 0, n - 1);
    clock_t t;
    t = clock();
    insertionSort(a, n);
    t = clock() - t;

    double time_taken = (double)t; // in seconds

    printf("insertionSort() took %f seconds to execute \n", time_taken);
    return 0;
}