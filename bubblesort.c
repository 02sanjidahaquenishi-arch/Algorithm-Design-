#include <stdio.h>

int main()
{
    int numbers[] = {7, 4, 5, 8, 1, 11};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int round = 0; round < n - 1; round++)
    {
        for (int bullet = 0; bullet < n - 1 - round; bullet++)
        {
            if (numbers[bullet] > numbers[bullet + 1])
            {
                int temp = numbers[bullet];
                numbers[bullet] = numbers[bullet + 1];
                numbers[bullet + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}