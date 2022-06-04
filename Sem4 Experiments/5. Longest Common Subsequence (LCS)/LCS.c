#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "ABABCDE";
    char s2[] = "BACADB";

    printf("Enter the 1st string: ");
    scanf("%s", s1);
    printf("Enter the 2nd string: ");
    scanf("%s", s2);

    int m = strlen(s1);
    int n = strlen(s2);
    int val[m + 1][n + 1], arr[m][n];

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                val[i][j] = 0;
            }
            else if (i > 0 && j > 0 && s1[i - 1] == s2[j - 1])
            {
                val[i][j] = 1 + val[i - 1][j - 1];
                arr[i - 1][j - 1] = 1;
            }
            else if (i > 0 && j > 0 && s1[i - 1] != s2[j - 1])
            {
                if (val[i - 1][j] > val[i][j - 1])
                {
                    val[i][j] = val[i - 1][j];
                    arr[i - 1][j - 1] = 2;
                }
                else
                {
                    val[i][j] = val[i][j - 1];
                    arr[i - 1][j - 1] = 3;
                }
            }
        }
    }

    /*
     * 1 - Diagonal
     * 2 - Top
     * 3 - Left
     */
    printf("\nValues Array - \n");
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%d ", val[i][j]);
        }
        printf("\n");
    }

    printf("\nIndexing\n1 - Diagonal\n2 - Top\n3 - Left\n\n");
    printf("\nArrow Array - \n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Index: %d", n);
    printf("\nValue at index  = %d\n", val[m][n]);

    int j = n - 1;
    int i = m - 1;
    char lcs[m];
    int k = 0;

    while (i >= 0 && j >= 0)
    {
        switch (arr[i][j])
        {
        case 1:
            lcs[k] = s1[i];
            i--;
            j--;
            k++;
            break;
        case 2:
            i--;
            break;
        case 3:
            j--;
            break;

        default:
            break;
        }
    }
    printf("\nLongest Common Subsequence: ");
    for (int i = 0; i < k; i++)
    {
        printf("%c", lcs[i]);
    }
    printf("\n");
    for (int i = 0; i < k / 2; i++)
    {
        char temp = lcs[i];
        lcs[i] = lcs[k - i - 1];
        lcs[k - i - 1] = temp;
    }
    printf("\nLongest Common Subsequence: ");
    for (int i = 0; i < k; i++)
    {
        printf("%c", lcs[i]);
    }
    printf("\n");
}