#include<bits/stdc++.h>
#define ll long 
#define MOD 1000000007
using namespace std;
ll grid[1001][1001];
int countPaths(ll m,ll n)
{
	
	//Initialising the Dp problems
	if(grid[0][0]==-1)
	return 0;
	
	for(ll i=0;i<m;i++)
	{
		if(grid[i][0]==-1)
		break;
		else
		grid[i][0]=1;
	}
	
	for(ll i=0;i<n;i++)
	{
		if(grid[0][i]==-1)
		break;
		else
		grid[0][i]=1;
	}
	
	
	for(ll r=1;r<m;r++)
	{
		for(ll c=1;c<n;c++)
		{
			if(grid[r][c]==-1)
			continue;
			//grid[r][c]=0;
			
			if(grid[r][c-1]!=-1)
			grid[r][c]=grid[r][c-1]%MOD;
			
			if(grid[r-1][c]!=-1)
			grid[r][c]=(grid[r][c]+grid[r-1][c])%MOD;
		}
	}
	
	if(grid[m-1][n-1]==-1)
	return 0;
	
	return grid[m-1][n-1];
	
}

int main()
{
	ll m,n,p;
	cin>>m>>n>>p;
	memset(grid,0,sizeof(grid));
	for(ll i=1;i<=p;i++)
	{
		ll r,c;
		cin>>r>>c;
		grid[r-1][c-1]=-1;
	}
	cout<<countPaths(m,n)<<endl;;
	return 0;
}
	
