#include <stdio.h>

void makeChange(int amount)
{
    int coins[] = {100, 50, 20, 10, 5, 2, 1};
    int n = 7;

    printf("Coins used:\n");

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        while(amount >= coins[i])
        {
            amount = amount - coins[i];
            count++;
        }

        if(count > 0)
        {
            printf("%d coin(s) of %d\n", count, coins[i]);
        }
    }
}

int main()
{
    int amount;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    makeChange(amount);

    return 0;
}