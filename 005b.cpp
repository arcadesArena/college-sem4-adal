/*
date: 2022.06.02
lab set: 5 b
5. Apply decrease and conquer technique to implement the following
a) Display nodes visited in the order starting from a given node in a graph using Depth First Search and also display push and pop order of the nodes.
b) Print all nodes reachable from a given node in a digraph using Breadth First Search
*/
#include<bits/stdc++.h>
using namespace std;
int que[20],visit[20],rear=-1,frnt=0,n,s,adj[20][20],flag=0;
void qinsert(int v){
    que[++rear]=v;
}
int qdelete(){
    return (que[frnt++]);
}
int qempty(){
    if(rear<frnt)
        return 1;
    return 0;
}
void bfs(int v){
    int w;
    visit[v]=1;
    qinsert(v);
    while(!qempty()){
        v=qdelete();
        for(w=1;w<=n;w++){
            if((adj[v][w]==1) && (visit[w]==0)){
                visit[w]=1;
                flag=1;
                cout<<w<<"\t";
                qinsert(w);
            }
        }
    }
}
int main(){
    int v,w;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix:"<<endl;
    for(v=1;v<=n;v++){
        for(w=1;w<=n;w++)
            cin>>adj[v][w];
    }
    cout<<"Enter the start vertex: ";
    cin>>s;
    cout<<"Reachability of vertex "<<s<<endl;
    for(v=1;v<=n;v++)
        visit[v]=0;
    bfs(s);
    if(flag==0)
        cout<<"No path found"<<endl;
    return 0;
}
