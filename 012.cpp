/*
date:
lab set: 12
12. Apply Greedy technique to develop a program to implement Prim’s algorithm to find minimum cost spanning tree of a given weighted graph.
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
int a,b,u,v,n,i,j,m,ne=1;
int visited[10]= {10};
int mincost =0;
int cost [10][10];
int main(){
    cout<<"\nprims: enter no. of nodes: ";
    cin>>n;
    cout<<"\nenter adj matrix: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;
    while(ne<n){
        for(i=1,m=999; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<m)
                    if(visited[i]!=0){
                        m=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if(visited[u]==0||visited[v]==0){
            cout<<"\nedge"<<ne++<<":("<<a<<","<<b<<")-->"<<"cost ="<<m;
            mincost+=m;
            visited[0]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<"\nmincost ="<<mincost;
    return 0;
}
