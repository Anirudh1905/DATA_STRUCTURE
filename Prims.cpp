// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V 9
vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)  //optimized
{
	vector<vector<int> > graph(V, vector<int>(V, 0));
	for(int i=0; i<V; i++)
	    for(int j=0; j<adj[i].size(); j++)
		graph[i][adj[i][j][0]] = adj[i][j][1];
	vector<int>value(V,INT_MAX);
	vector<bool>processed(V,false);
	value[src]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});
	while(!pq.empty())
	{
	    int u=pq.top().second;
	    pq.pop();
	    processed[u]=true;
	    for(int v=0;v<V;v++)
	    {
    		if(graph[u][v]!=0 && processed[v]==false && graph[u][v]<value[v])
    		{
    		    value[v]=value[u]+graph[u][v];
    		    pq.push({value[v],v});
    
    		}
	    }
	}
	return value;
}
int minDistance(vector<int>value,vector<bool>processed)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (processed[v] == false && value[v] <= min)
			min = value[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(vector<int>dist)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void prims(int graph[V][V], int src)
{
    int parent[V];
    vector<int>value(V,INT_MAX);
    vector<bool>processed(V,false);
    parent[src]=-1;
    value[src]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=minDistance(value,processed);
        processed[u]=true;
        for(int j=0;j<V;j++)
        {
            if(graph[u][j]!=0 && processed[j]==false && (graph[u][j]<value[j]))
            {
                value[j]=value[u]+graph[u][j];
                parent[j]=u;
            }
        }
    }
	printSolution(value);
}

// driver program to test above function
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	prims(graph, 0);

	return 0;
}
