#include <stdio.h>

int leftBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int pos = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            pos = mid;
            high = mid - 1;   
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return pos;
}

int rightBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int pos = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            pos = mid;
            low = mid + 1;    
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return pos;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = 7;
    int x = 2;

    printf("Left Bound = %d\n", leftBound(arr, n, x));
    printf("Right Bound = %d\n", rightBound(arr, n, x));

    return 0;
}