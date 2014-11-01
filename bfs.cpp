#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;

bool pathexists;
int some_vertex, source_main,sink_main;
void print(int i, int * parent){
		if(i==source_main){
			printf("%d\n",source_main);
			return;
		}
		print(parent[i],parent);
		printf("%d\n",i);
	}
class Graph
{
	public:
		int number_of_vertices;

		list<int> *adj;
		Graph(int vertices)
		{
			this->number_of_vertices=vertices;
			adj = new list<int>[vertices];
		}
		void Add_Edge(int start,int end)
		{
			adj[start].push_back(end);
		}
		void BFS(int source,int sink)
		{
			if(source==sink)
			{
				printf("%d\n%d\n",source,sink );
				exit(0);
			}
			pathexists=false;
			int parent[number_of_vertices];
			//printed the source
			bool *visited = new bool[number_of_vertices];
			for (int i = 0; i < number_of_vertices; ++i)
			{
				visited[i]= false;
				parent[i]=-1;
			}
			list<int> queue;
			visited[source]= true;
			list<int>::iterator i;
			queue.push_back(source);
			parent[number_of_vertices] = -1;
			while((!queue.empty())&&(!pathexists))
			{
				some_vertex=queue.front();
				if(sink == some_vertex)
					{
						pathexists=true;
						print(sink,parent);
						break;
					}
				queue.pop_front();
				for (i = adj[some_vertex].begin(); i != adj[some_vertex].end(); ++i)
				{
					if(visited[*i]==false)
					{
						visited[*i] = true;
						queue.push_back(*i);
						parent[*i]=some_vertex;
					}
				}
			}
			if(!pathexists)
			{
				printf("-1\n");
			}
		}
};
int main()
{
	int number_of_vertices,vertex1,vertex2;
	scanf("%d%d%d",&number_of_vertices,&source_main,&sink_main);
	Graph G(number_of_vertices);
	while(scanf("%d%d",&vertex1,&vertex2) != EOF)
	{
		G.Add_Edge(vertex1,vertex2);
	}
	G.BFS(source_main,sink_main);
}