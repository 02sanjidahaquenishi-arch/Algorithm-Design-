#include <stdio.h>

int main()
{
    int n, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}