// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Array to store the in-degree of node
int indegree[maxN];

// Array to store the time in which
// the job i can be done
int job[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n, int m)
{
    queue<int>q;vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            ans[i]=1;
        }
    }
    while(!q.empty())
    {
        int tmp=q.front();q.pop();
        for(auto x:graph[tmp])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
                ans[x]=ans[tmp]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}

// Driver Code
int main()
{
	// Given Nodes N and edges M
	int n, m;
	n = 10;
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	printOrder(n, m);
	return 0;
}
