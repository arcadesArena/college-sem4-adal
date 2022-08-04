/*
date:
lab set: 9 b
9. Apply dynamic programming technique to implement
a) 0/1 Knapsack problem.
b) Compute the transitive closure of a given graph using Warshall's algorithm.
*/
#include<bits/stdc++.h>
using namespace std;
void warshall(int a[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
        }
    }
}
int main(){
    int n,a[10][10];
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    warshall(a,n);
    cout<<"The transitive closure of the given graph:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
