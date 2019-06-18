#include<iostream>
using namespace std;
string st1,st2;
int solve(int m,int n)
{
	int dp[m+1][n+1],len=-1;
	for(int i=0;i<m;i++) dp[i][0]=0;
	for(int j=0;j<n;j++) dp[0][j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(st1[i-1]==st2[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=0;
			len=max(len,dp[i][j]);
		}
	}
	return len;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		cin>>st1>>st2;
		cout<<solve(m,n)<<endl;
	}
	return 0;
}
	
