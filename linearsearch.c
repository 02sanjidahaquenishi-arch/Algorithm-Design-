#include <stdio.h>

int main() {
    int n, search;
    int found = 0;

    scanf("%d", &n);
    
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++) {
        if (a[i] == search) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Found");
    } else {
        printf("Not Found");
    }

    return 0;
}