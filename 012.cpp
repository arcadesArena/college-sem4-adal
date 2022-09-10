/*
date:
lab set: 12
12. Apply Greedy technique to develop a program to implement Prim's algorithm to find minimum cost spanning tree of a given weighted graph.
*/
#include <stdio.h>
#define MAX 100
#define INF 999
int find_min(int distance[MAX], int visited[MAX], int n)
{
    int min = INF;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && distance[i] < min)
        {
            min = distance[i];
            index = i;
        }
    }
    return index;
}
void display(int graph[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
}
void prims(int graph[MAX][MAX], int n)
{
    int distance[MAX], visited[MAX], parent[MAX];
    int i, index, j;
    int tree[MAX][MAX];
    for (i = 0; i < n; i++)
    {
        distance[i] = graph[0][i];
        visited[i] = 0;
        parent[i] = 0;
        for (j = 0; j < n; j++)
            tree[i][j] = 0;
    }
    visited[0] = 1;
    int sum = 0;
    for (int count = 0; count < n; count++)
    {
        index = find_min(distance, visited, n);
        sum += graph[parent[index]][index];
        tree[index][parent[index]] = tree[parent[index]][index] = distance[index];
        visited[index] = 1;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && graph[index][j] < distance[j])
            {
                distance[j] = graph[index][j];
                parent[j] = index;
            }
        }
    }
    if (sum > INF)
        printf("spanning tree does not exist\n");
    else
    {
        printf("spanning tree\n");
        display(tree, n);
    }
}
void read_input(int graph[MAX][MAX], int n)
{
    int i, j;
    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
}
int main()
{
    int graph[MAX][MAX], n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    read_input(graph, n);
    prims(graph, n);
    return 0;
}
