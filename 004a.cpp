/*
date: 2022.05.26
lab set: 4 a
4. Apply decrease and conquer technique to implement
a) Topological ordering of vertices in a given digraph.
b) Insertion sort algorithm to sort a given set of elements
*/
#include<bits/stdc++.h>
using namespace std;
int temp[10],k=0;
void topo(int n,int indegree[10],int a[10][10]){
    int i,j;
    for(i=1;i<=n;i++){
        if(indegree[i]==0){
            indegree[i]=1;
            temp[++k]=i;
            for(j=1;j<=n;j++){
                if(a[i][j]==1 && indegree[j]!=-1)
                    indegree[j]--;
            }
            i=0;
        }
    }
}
int main(){
    int i,j,n,indegree[10],a[10][10];
    cout<<"Enter the number of vertex:";
    cin>>n;
    for(i=1;i<=n;i++)
        indegree[i]=0;
    cout<<"Enter the adjacency matrix:\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==1)
                indegree[j]++;
        }
    }
    topo(n,indegree,a);
    if(k!=n)
        cout<<"Topological ordering is not possible"<<endl;
    else{
        cout<<"Topological ordering is: ";
        for(i=1;i<=k;i++)
            cout<<"v"<<temp[i]<<"\t";
    }
    return 0;
}
