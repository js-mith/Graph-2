#include <iostream>
#include <climits>
using namespace std;

long findMinimumVertex(long *distance, bool *visited, long v)
{
    long vertex = -1;
    for (long i = 0; i < v; i++)
    {
        if (!visited[i] && (vertex == -1 || distance[i] < distance[vertex]))
            vertex = i;
    }
    return vertex;
}

int main() {
    // Write your code here

     long v, e;
    cin >> v >> e;
    long **edges = new long *[v];
    for (long i = 0; i < v; i++)
    {
        edges[i] = new long[v];
        for (long j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    for (long i = 0; i < e; i++)
    {
        long start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    // Dijkstra's algorithm

    bool *visited = new bool[v];
    long *distance = new long[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (long i = 0; i < v; i++)
    {
        long vertex = findMinimumVertex(distance, visited, v);
        visited[vertex] = true;
        for (long j = 0; j < v; j++)
        {
            if (edges[vertex][j] && edges[vertex][j] < distance[j] && !visited[j] && (distance[vertex] + edges[vertex][j]) < distance[j])
                distance[j] = distance[vertex] + edges[vertex][j];
        }
    }

    for (long i = 0; i < v; i++)
        cout << i << " " << distance[i] << "\n";

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete[] edges;
    delete[] distance;
    delete[] visited;
    return 0;
}