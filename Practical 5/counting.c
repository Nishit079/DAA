#include <stdio.h>

void countingSort(int arr[], int n)
{
    int i;
    
    // Find maximum element
    int max = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    int output[n];

    // Initialize count array
    for(i = 0; i <= max; i++)
        count[i] = 0;

    // Store count of each element
    for(i = 0; i < n; i++)
        count[arr[i]]++;

    // Store cumulative count
    for(i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array
    for(i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy to original array
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements (non-negative integers):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
