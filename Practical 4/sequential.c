#include <stdio.h>

int sequentialSearch(int arr[], int n, int key, int *steps)
{
    int i;
    *steps = 0;

    for(i = 0; i < n; i++)
    {
        (*steps)++;   
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key, i, position;
    int steps;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    position = sequentialSearch(arr, n, key, &steps);

    if(position != -1)
        printf("Element found at position %d\n", position + 1);
    else
        printf("Element not found\n");

    printf("Total steps executed: %d\n", steps);

    return 0;
}
