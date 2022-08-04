/*
date: 2022.07.21
lab set: 13
13. Apply Greedy technique to implement Kruskal's algorithm to find minimum cost spanning tree of a given weighted graph.
*/
#include<bits/stdc++.h>
using namespace std;
int i,j,k,a,b,u,v,n,ne=1,minm,mincost=0,cost[9][9],parent[9];
int find(int i){
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main(){
    cout<<"Implementation of Krushkal's algorithm\n";
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    cout<<"The edges of minimum cost spanning tree are\n";
    while(ne<n){
        for(i=1,minm=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<minm){
                    minm=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            cout<<ne++<<" edge ("<<a<<","<<b<<")="<<minm<<endl;
            mincost+=minm;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<"Minimum cost = "<<mincost<<endl;
    return 0;
}
