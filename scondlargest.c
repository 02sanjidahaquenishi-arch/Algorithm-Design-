#include <stdio.h>

int main()
{
    int n;
    int largest, second;
    int foundSecond = 0;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    largest = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (a[i] != largest)
        {
            if (foundSecond == 0 || a[i] > second)
            {
                second = a[i];
                foundSecond = 1;
            }
        }
    }

    if (foundSecond == 0)
    {
        printf("No second largest distinct element");
    }
    else
    {
        printf("Second largest = %d", second);
    }
