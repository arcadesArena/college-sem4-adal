/*
date: 2022.04.28
lab set: 1 b
1. Apply brute force/divide and conquer technique to recursively implement the following concepts:
a) Linear Search and Binary Search.
b) To find the maximum and minimum in a given list of n elements.
*/
#include <stdio.h>
#include <stdlib.h>
int m,mm;
void minMax(int a[],int n){
    int t;
    if(n<0){
        printf("max:%d\n",m);
        printf("min:%d\n",mm);
        return;
    }
    if(a[n]>m)
        m=t=a[n];
    if(a[n]<mm)
        mm=t=a[n];
    minMax(a,n-1);
}
int main()
{
    int n;
    printf("Enter the number array elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d array elements:\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    mm=m=a[n-1];
    printf("With recursion\n");
    minMax(a,n-2);
    return 0;
}
