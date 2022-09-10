/*
date:
lab set: 15
15.Apply Back Tracking technique to implement a program on nQueen's problem.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int solutions = 0;
void showBoard(int table[MAX], int n)
{
    int i, j;
    printf("\nSolution # %d\n\n", ++solutions);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == table[i])
                printf("Q ");
            else
                printf("# ");
        }
        printf("\n");
    }
    printf("\n");
}
int checkNext(int table[MAX], int row, int column)
{
    for (int i = 0; i < row; i++)
        if (table[i] == column || abs(table[i] - column) == abs(i - row))
            return 0;
    return 1;
}
void NQueen(int table[MAX], int row, int column)
{
    for (int i = 0; i < column; i++)
    {
        if (checkNext(table, row, i))
        {
            table[row] = i;
            if (row == column - 1)
                showBoard(table, column);
            NQueen(table, row + 1, column);
        }
    }
}
int main()
{
    int n;
    int table[MAX];
    printf("Enter the number of queens : ");
    scanf("%d", &n);
    NQueen(table, 0, n);
    if (solutions)
        printf("Number of solution for the given problem instance is :%d\n", solutions);
    else
        printf("No solution exists for the given problem instance.\n");
    return 0;
}