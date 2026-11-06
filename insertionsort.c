#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int item = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > item)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = item;
    }

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}