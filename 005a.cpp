/*
date:
lab set: 5 a
5. Apply decrease and conquer technique to implement the following
a) Display nodes visited in the order starting from a given node in a graph using Depth First Search and also display push and pop order of the nodes.
b) Print all nodes reachable from a given node in a digraph using Breadth First Search
*/
#include<bits/stdc++.h>
using namespace std;
int G[10][10],visited[10],n,in;
void dfs(int i){
    cout<<i<<"\t";
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(!visited[j] &&G[i][j]==1)
            dfs(j);
    }
}
int main(){
    int i,j;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the input vertex: ";
    cin>>in;
    cout<<"Enter the adjacency matrix:\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cin>>G[i][j];
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    dfs(in);
    return 0;
}
