
#include<iostream>
using namespace std;
int grid[1001][1001];
int solve(int grid[][1001],int n)
{
    for(int i=0;i<n;i++)
    {
        int m;
        for(int j=0;j<n;j++)
        {
            m=0;
            if(i-1>=0)
            m=max(m,grid[i-1][j]);
            if(i-1>=0 && j+1<n)
            m=max(m,grid[i-1][j+1]);
            if(i-1>=0 && j-1>=0)
            m=max(m,grid[i-1][j-1]);
            grid[i][j]+=m;
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++)
    ans=max(ans,grid[n-1][i]);
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        cin>>grid[i][j];
	    }
	    cout<<solve(grid,n)<<endl;
	}
	
	return 0;
}
