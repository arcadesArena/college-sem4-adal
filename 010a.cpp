/*
date:
lab set: 10 a
10. Apply dynamic programming technique to implement
a) All pair shortest path problem using Floyd's algorithm.
b) Find the Binomial Coefficient.
*/
#include<bits/stdc++.h>
using namespace std;
int mini(int a,int b){
    return (a<b?a:b);
}
void floyds(int a[10][10],int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                a[i][j]=mini(a[i][j],a[i][k]+a[k][j]);
        }
    }
}
int main(){
    int n,a[10][10];
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the adjacency matrix (INF=999)"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    floyds(a,n);
    cout<<"All pair shortest path of given graph"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
