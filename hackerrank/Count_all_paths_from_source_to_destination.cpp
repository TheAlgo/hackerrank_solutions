#include <bits/stdc++.h>
using namespace std;


void bfs(int s,int d,vector<int>adj[],bool vis[],int &count)
{
    vis[s]=false;
    if(s==d)
    {
        count++;
    }
    vector<int>::iterator iter;
    for(iter=adj[s].begin();iter!=adj[s].end();iter++)
    {
        if(vis[*iter]==true)
        {
            bfs((*iter),d,adj,vis,count);
        }
    }
    vis[s]=true;
}

int main() {
    
    int tc,v,e,s,d,k,m;
    cin>>tc;
    while(tc--)
    {
        cin>>v>>e;
        vector<int>adj[v];
        while(e--)
        {
            cin>>k>>m;
            adj[k].push_back(m);
        }
        cin>>s>>d;
        int count=0;
        bool vis[v];
        memset(vis,true,sizeof(vis));
        bfs(s,d,adj,vis,count);
        cout<<count<<endl;
    }
	return 0;
}
