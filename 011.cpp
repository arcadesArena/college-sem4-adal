/*
date:
lab set: 11
11. Apply Greedy technique to implement a program to find shortest paths to other vertices using Dijkstra's algorithm from a given vertex in a weighted connected graph.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999
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
void print_path(int index, int parent[MAX], int source)
{
    if (parent[index] == source)
        printf("%d", source);
    else
        print_path(parent[index], parent, source);
    printf(" --> %d", index);
}
void find_djkstra(int graph[MAX][MAX], int n, int source)
{
    int distance[MAX], parent[MAX], visited[MAX];
    int i, index, j;
    for (i = 0; i < n; i++)
    {
        parent[i] = source;
        distance[i] = graph[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;
    for (i = 1; i < n; i++)
    {
        index = find_min(distance, visited, n);
        if (index == -1)
            return;
        visited[index] = 1;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                if (distance[index] + graph[index][j] <
                    distance[j])
                {
                    distance[j] = distance[index] +
                                  graph[index][j];
                    parent[j] = index;
                }
            }
        }
        print_path(index, parent, source);
        printf(" = %d \n", distance[index]);
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
        printf("\n");
    }
}
int main()
{
    int graph[MAX][MAX], n, source;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    read_input(graph, n);
    printf("\nEnter the source vertex : ");
    scanf("%d", &source);
    printf("shortest path : \n");
    find_djkstra(graph, n, source);
    return 0;
}
