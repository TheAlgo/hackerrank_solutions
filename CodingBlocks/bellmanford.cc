#include<iostream>
#include<climits>
using namespace std;
class Edge
{
	public:
	int src,dest,weight;
};

class Graph
{
	public:
	int v,e;
	Edge *edge;
	Graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		edge=new Edge[e];
	}
	void addEdge(int s,int d,int w,int count)
	{
		edge[count].src=s;
		edge[count].dest=d;
		edge[count].weight=w;
	}
	void bellmanford(int src)
	{
		int dist[v];
		for(int i=0;i<v;i++)
		dist[i]=INT_MAX;
		dist[src]=0;
		
		for(int i=1;i<=v-1;i++)
		{
			for(int j=0;j<e;j++)
			{
				int src=edge[i].src;
				int dest=edge[i].dest;
				int weight=edge[i].weight;
				if(dist[dest]>dist[src]+weight)
				dist[dest]=dist[src]+weight;
			}
		}
		//printing the distances
		for(int i=0;i<v;i++)
		cout<<dist[i]<<" ";
		cout<<endl;
	}
};
	
	int main()
	{
		int v;
		cin>>v;
		int e;
		cin>>e;
		Graph g(v,e);
		//Adding the edges of the graph and printing the valuesd
		return 0;
		
	}
