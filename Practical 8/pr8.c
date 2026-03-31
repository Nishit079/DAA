 #include <stdio.h>
#define MAX 100

int minCoins(int coins[], int n, int amount)
{
    int dp[MAX];
    int i, j;

    // Initialize dp array
    for(i = 0; i <= amount; i++)
        dp[i] = 10000; // large value (infinity)

    dp[0] = 0; // base case

    for(i = 1; i <= amount; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                if(dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount];
}
int main()
{
    int n, amount, i;
    printf("Enter number of coin types: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter coin denominations:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    printf("Enter amount: ");
    scanf("%d", &amount);
    int result = minCoins(coins, n, amount);
    printf("Minimum coins required = %d\n", result);
    return 0;
}
