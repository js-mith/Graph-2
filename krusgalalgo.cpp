#include <iostream>
#include <algorithm>
using namespace std;

class Edges
{
public:
    long source;
    long destination;
    long weight;
};

bool compareWeight(Edges e1, Edges e2)
{
    return (e1.weight < e2.weight);
}

long find(long v, long *parents)
{
    if (v == parents[v])
        return v;
    return find(parents[v], parents);
}

void Union(Edges *output, Edges *input, long v, long *parents)
{
    long count = 0, i = 0;
    while (count < (v - 1))
    {
        long parentSource = find(input[i].source, parents);
        long parentDestination = find(input[i].destination, parents);
        if (parentSource != parentDestination)
        {
            output[count] = input[i];
            count++;
            parents[parentSource] = parents[parentDestination];
        }
        i++;
    }
}

int main() {
    // Write your code here
      long v, e;
    cin >> v >> e;
    Edges *input = new Edges[e];
    for (long i = 0; i < e; i++)
        cin >> input[i].source >> input[i].destination >> input[i].weight;

    // Kruskal's algorithm

    sort(input, input + e, compareWeight);

    long *parents = new long[v];
    for (long i = 0; i < v; i++)
        parents[i] = i;

    Edges *output = new Edges[v - 1];
    Union(output, input, v, parents);

    for (long i = 0; i < (v - 1); i++)
        cout << min(output[i].source, output[i].destination) << " " << max(output[i].source, output[i].destination) << " " << output[i].weight << "\n";

    delete[] input;
    delete[] parents;
    delete[] output;
    return 0;
}