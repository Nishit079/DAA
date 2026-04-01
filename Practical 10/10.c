#include <stdio.h>
#define MAX 20
int board[MAX];
int n;
int steps = 0;
// Function to check if position is safe
int isSafe(int row, int col)
{
    int i;
    for(i = 0; i < col; i++)
    {
        steps++;
        // Check same row or diagonal
        if(board[i] == row || 
           (board[i] - i == row - col) || 
           (board[i] + i == row + col))
            return 0;
    }
    return 1;
}
int solve(int col)                                                   // Backtracking function
{
    int row;
    if(col == n)
        return 1;
   for(row = 0; row < n; row++)
    {
        if(isSafe(row, col))
        {
            board[col] = row;
            if(solve(col + 1))
                return 1;
        }
    }
    return 0;
}
void printSolution()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(board[j] == i)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if(solve(0))
    {
        printf("Solution:\n");
        printSolution();
        printf("Total steps = %d\n", steps);
    }
    else
        printf("No solution exists.\n");
    return 0;
}
