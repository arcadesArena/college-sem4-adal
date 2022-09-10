/*
date:
lab set: 14
14.Apply Back Tracking technique to implement a program to find a subset of a given set S = {s1, s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 there are two solutions {1,2,6} and {1,8}. A suitable message is to be displayed if the given problem instance doesn't have a solution.
*/
#include <stdio.h>
#define MAX 100
int stack[MAX];
int item[MAX];
int size, top = -1;
int issolved = 1, count = 0;
void display()
{
    printf("\nSOLUTION %d\n{ ", ++count);
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("}\n\n");
}
void push(int data)
{
    stack[++top] = data;
}
void pop()
{
    top--;
}
void findSubset(int pos, int sum)
{
    if (sum > 0)
    {
        for (int i = pos; i <= size; i++)
        {
            push(i);
            findSubset(i + 1, sum - item[i]);
            pop();
        }
    }
    if (sum == 0)
    {
        display();
        issolved = 0;
    }
}
int main()
{
    int sum;
    printf("Enter the maximum number of elements : ");
    scanf("%d", &size);
    printf("Enter the weights of the elements : \n");
    for (int i = 1; i <= size; i++)
        scanf("%d", &item[i]);
    printf("Enter the total required weight : ");
    scanf("%d", &sum);
    findSubset(1, sum);
    if (issolved)
        printf("\n\nThe given problem instance doesn't have any solution.\n");
    return 0;
}
