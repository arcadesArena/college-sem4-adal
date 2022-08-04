/*
date:
lab set: 11
11. Apply Greedy technique to implement a program to find shortest paths to other vertices using Dijkstra's algorithm from a given vertex in a weighted connected graph.
*/
#include<stdio.h>
#include<stdlib.h>
const int max = 10,inf=9999;
void fndijkstra(int c[max][max],int d[max],int p[max],int s[max],int so,int de,int n){
    int i,j,a,b,min;
    for(i=0; i<n; i++){
        s[i] = 0;
        d[i] = c[so][i];
        p[i] = so;
    }
    s[so] = 1;
    for(i=1; i<n; i++){
        min = inf;
        a = -1;
        for(j=0; j<n; j++){
            if(s[j] == 0){
                if(d[j] < min){
                    min = d[j];
                    a = j;
                }
            }
        }
        if(a == -1)
            return;
        s[a] = 1;
        if(a == de)
            return;
        for(b=0; b<n; b++){
            if(s[b] == 0){
                if(d[a] + c[a][b] < d[b]){
                    d[b] = d[a] + c[a][b];
                    p[b] = a;
                }
            }
        }
    }
}
int main(){
    int n,cost[max][max],dist[max],visited[max],path[max],i,j,source,dest;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix : ");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&cost[i][j]);
    for(source = 0; source<n; source++){
        printf("\nSource vertex : %d shortest path to other vertices \n",source);
        for(dest = 0; dest<n; dest++){
            fndijkstra(cost,dist,path,visited,source,dest,n);
            if(dist[dest] == inf)
                printf("%d not reachable\n",dest);
            else{
                printf("\n");
                i = dest;
                do{
                    printf("%d<--",i);
                    i = path[i];
                }
                while(i != source);
                printf("%d = %d\n",i,dist[dest]);
            }
        }
        printf("press enter to continue....\n");
    }
    return 0;
}
