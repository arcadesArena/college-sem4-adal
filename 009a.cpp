/*
date:
lab set: 9 a
9. Apply dynamic programming technique to implement
a) 0/1 Knapsack problem.
b) Compute the transitive closure of a given graph using Warshall's algorithm.
*/
/*#include <bits/stdc++.h>
using namespace std;
int knapsack(int* w,int *p,int n,int m){
    if(m==0)
        return 0;
    if(n==0)
        return 0;
    if(w[n-1]>m)
        return knapsack(w,p,n-1,m);
    return max(knapsack(w,p,n-1,m),p[n-1]+knapsack(w,p,n-1,m-w[n-1]));
}
int main()
{
    int i,n,m;
    cout<<"Enter the number of items :";
    cin>>n;
    int w[n],p[n];
    cout<<"Enter the weight and price of all items :"<<endl;
    for(i = 0;i<n;i++){
        cin>>w[i]>>p[i];
    }
    cout<<"Enter the capacity of knapsack :";
    cin>>m;
    cout<<"The maximum value of items that can be put into knapsack is :"<<knapsack(w,p,n,m);
    return 0;
}*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int knapsack_dp(int n,int m,int w[],int p[]){
    int i,j;
    int knapsack[n+1][m+1]={0};
    for(j=0;j<=m;j++)
        knapsack[0][j]=0;
    for(i=0;i<=n;i++)
        knapsack[i][0]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(w[i-1]<=j)
                knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
            else
                knapsack[i][j]=knapsack[i-1][j];
        }
    }
    return knapsack[n][m];
}
int main(){
    int i,n,m;
    cout<<"Enter number of items: ";
    cin>>n;
    int w[n],p[n];
    cout<<"Enter weight and price of all items:"<<endl;
    for(i=0;i<n;i++)
        cin>>w[i]>>p[i];
    cout<<"Enter the capacity of knapsack: ";
    cin>>m;
    int result=knapsack_dp(n,m,w,p);
    cout<<"The maximum value of items that can be put in knapsack is "<<result<<endl;
    return 0;
}

