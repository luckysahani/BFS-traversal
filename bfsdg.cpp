// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef pair<int,int> shortestPath;

bool Compare(const shortestPath &a, const shortestPath &b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}



// This class represents a directed graph using adjacency list representation
class Graph
{
	int V;    // No. of vertices
	int S,T;
	list<int> *adj;    // Pointer to an array containing adjacency lists
	//int ** weight;

	public:
	Graph(int V, int S, int T){
		this->V = V;
		this->S = S;
		this->T = T;
		adj = new list<int>[V];
		//weight = (int**)calloc(V,sizeof(int*));
		//int i;
		//for(i=0;i<V;i++) weight[i] = (int*)calloc(V,sizeof(int));
		readGraph();
	}

	void addEdge(int u, int v){
		adj[u].push_back(v); // Add w to v’s list.
		//weight[u][v] = w;
	}

	void readGraph(){
		int u,v;
		while(scanf("%d %d",&u, &v) != EOF) addEdge(u,v);
	}

	void print(int i, int * parent){
		if(i==S){
			printf("%d\n",S);
			return;
		}
		print(parent[i],parent);
		printf("%d\n",i);
	}

	void BFS()
	{
		int s = S;

		// Mark all the vertices as not visited
		bool *visited = new bool[V];
		//int delta[V];
		int parent[V];
		int flag=0;
		//shortestPath result[V-1];
		//int count=0;

		for(int i = 0; i < V; i++){
			visited[i] = false;
			//delta[i] = INT_MAX;
			parent[i] = -1;
		}

		// Create a queue for BFS
		list<int> queue;


		// Mark the current node as visited and enqueue it
		visited[s] = true;
		queue.push_back(s);
		//delta[s] = 0;
		parent[V] = -1;

		// 'i' will be used to get all adjacent vertices of a vertex
		list<int>::iterator i;

		while(!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			s = queue.front();
			//cout << s << " " << delta[s] << '\n';

			//result[count].first = s;
			//result[count].second = delta[s];
			//count++;

			if(s==T){
				print(T,parent);
				flag=1;
				break;
			}

			queue.pop_front();

			// Get all adjacent vertices of the dequeued vertex s
			// If a adjacent has not been visited, then mark it visited
			// and enqueue it
			for(i = adj[s].begin(); i != adj[s].end(); ++i)
			{
				if(!visited[*i])
				{
					visited[*i] = true;
					queue.push_back(*i);
					parent[*i] = s;
					//delta[*i] = delta[s] + weight[s][*i];
				}
			}
		}

		if(!flag) printf("-1\n");
		//sort(result,result+count,Compare);
		//for(int j=0;j<count;j++) printf("%d %d\n",result[j].first,result[j].second);
	}

};

int main()
{
	int V,S,T;
	scanf("%d",&V);
	scanf("%d %d",&S,&T);
	Graph g(V,S,T);

	g.BFS();

	return 0;
}
