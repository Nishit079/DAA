//1) Using Iteration Method 
#include<stdio.h>
void main()
{
    int n1 = 0, n2 = 1, n3;
    int i, n;
    int count = 0;

    printf("Enter nth Fibonacci number: ");
    scanf("%d", &n);
    count++;

    printf("The Fibonacci series is: ");
    printf("%d %d ", n1, n2);
    count += 2;

    for(i = 3; i <= n; i++)
    {
        count++;
        n3 = n1 + n2;
        count++;
        printf("%d ", n3);
        count++;
        n1 = n2;
        count++;
        n2 = n3;
        count++;
    }

    count++;
    printf("\nCount = %d", count);
}


 
