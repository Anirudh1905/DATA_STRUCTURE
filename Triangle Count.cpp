// C++ program to count triangles
// in a graph. The program is for
// adjacency matrix representation
// of the graph.
#include<bits/stdc++.h>

// Number of vertices in the graph
#define V 4

using namespace std;

// function to calculate the
// number of triangles in a
// simple directed/undirected
// graph. isDirected is true if
// the graph is directed, its
// false otherwise
int countTriangle(int g[V][V],
				bool isDirected)
{
	// Initialize result
	int count_Triangle = 0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(g[i][j] && g[j][k] && g[k][i])
                    count_Triangle++;
            }
        }
    }
    isDirected?count_Triangle/=3:count_Triangle/=6;
	return count_Triangle;
}

//driver function to check the program
int main()
{
	// Create adjacency matrix
	// of an undirected graph
	int graph[][V] = { {0, 1, 1, 0},
					{1, 0, 1, 1},
					{1, 1, 0, 1},
					{0, 1, 1, 0}
					};

	// Create adjacency matrix
	// of a directed graph
	int digraph[][V] = { {0, 0, 1, 0},
						{1, 0, 0, 1},
						{0, 1, 0, 0},
						{0, 0, 1, 0}
					};

	cout << "The Number of triangles in undirected graph : "
		<< countTriangle(graph, false);
	cout << "\n\nThe Number of triangles in directed graph : "
		<< countTriangle(digraph, true);

	return 0;
}
