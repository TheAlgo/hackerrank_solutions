#include<iostream>
#include<list>
#define ll long long
using namespace std;
class Graph
{
	ll v;
	list<ll> *l;
	public:
	Graph(int vertices)
	{
		v=vertices;
		l=new list<ll>[v];
	}
	
	void addEdge(ll a,ll b)
	{
		l[a].push_back(b);
		l[b].push_back(a);
	}
	void dfshelper(ll vertice,bool visited[],ll &count)
	{
		visited[vertice]=true;
		count++;
		
		for(auto i:l[vertice])
		{
			if(!visited[i])
			dfshelper(i,visited,count);
		}
	}
	void dfs(ll t,ll r)
	{
		bool visited[v]={false};
		ll n=v;
		ll total=0;
		for(ll i=0;i<n;i++)
		{
			ll count=0;
			if(!visited[i])
			{
				dfshelper(i,visited,count);
				total+=(count-1)*r+t;
			}
		}
		if(total<v*t)
		cout<<total<<endl;
		else
		cout<<v*t<<endl;
	}
};
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	ll n,e,t,r;
	cin>>n>>e>>t>>r;
	Graph g(n);
	for(ll i=1;i<=e;i++)
	{
		ll a,b;
		cin>>a>>b;
		g.addEdge(a-1,b-1);
	}
	g.dfs(t,r);
}
	return 0;
}

