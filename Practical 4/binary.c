#include <stdio.h>

int binarySearch(int arr[], int n, int key, int *steps)
{
    int low = 0, high = n - 1, mid;
    *steps = 0;

    while(low <= high)
    {
        (*steps)++;   
        
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
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

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    position = binarySearch(arr, n, key, &steps);

    if(position != -1)
        printf("Element found at position %d\n", position + 1);
    else
        printf("Element not found\n");

    printf("Total steps executed: %d\n", steps);

    return 0;
}
