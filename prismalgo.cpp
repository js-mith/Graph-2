#include <iostream>
#include <climits>
using namespace std;


long findMinimumVertex(long *weights, bool *visited, long v)
{
    long vertex = -1;
    for (long i = 0; i < v; i++)
    {
        if (!visited[i] && (vertex == -1 || weights[i] < weights[vertex]))
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

    // Prim's algorithm

    bool *visited = new bool[v];
    long *weights = new long[v];
    long *parents = new long[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parents[0] = -1;
    weights[0] = 0;

    for (long i = 0; i < (v - 1); i++)
    {
        long vertex = findMinimumVertex(weights, visited, v);
        visited[vertex] = true;
        for (long j = 0; j < v; j++)
        {
            if (edges[vertex][j] && !visited[j] && edges[vertex][j] < weights[j])
            {
                parents[j] = vertex;
                weights[j] = edges[vertex][j];
            }
        }
    }

    for (long i = 1; i < v; i++)
        cout << min(i, parents[i]) << " " << max(i, parents[i]) << " " << weights[i] << "\n";

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete[] edges;
    delete[] weights;
    delete[] parents;
    delete[] visited;
    return 0;
}