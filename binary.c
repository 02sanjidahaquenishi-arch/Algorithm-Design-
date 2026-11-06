#include <stdio.h>

int main()
{
    int number[8] = {3, 7, 13, 23, 45, 56, 67, 77};
    int target;
    int foundIndex = -1;

    printf("Enter an integer to search for: ");
    scanf("%d", &target);

    int left = 0;
    int right = 7;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (number[mid] == target)
        {
            foundIndex = mid;
            break;
        }
        else if (number[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (foundIndex != -1)
    {
        printf("%d was found at index %d\n", target, foundIndex);
    }
    else
    {
        printf("%d was not found in the array\n", target);
    }

    return 0;
}