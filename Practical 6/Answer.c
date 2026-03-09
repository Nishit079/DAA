#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

void fractionalKnapsack(struct Item items[], int n, int capacity)
{
    int i, j;
    struct Item temp;

    // Calculate profit/weight ratio
    for(i = 0; i < n; i++)
    {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Sort items in descending order of ratio (Greedy Choice)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalProfit = 0.0;
    int remainingCapacity = capacity;

    for(i = 0; i < n; i++)
    {
        if(items[i].weight <= remainingCapacity)
        {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        }
        else
        {
            totalProfit += items[i].profit * ((float)remainingCapacity / items[i].weight);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);
}

int main()
{
    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}