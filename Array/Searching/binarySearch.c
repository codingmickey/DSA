#include <stdio.h>

int binarySearch(int a[], int x, int n) {

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Binary Search
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int a[6] = {1, 3, 5, 6, 2, 7};
    int x, n = 6;
    printf("Enter a number to be found: ");
    scanf("%d", &x);

    int ans = binarySearch(a, x, n);

    if (ans == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index %d", ans);
    }

    return 0;
}