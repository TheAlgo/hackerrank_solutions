#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int n,dp[1000][1000];
int f(int i,int j,int arr[])
{
	if(i>j)
	return 0;
	
	int q1=arr[i]+min(f(i+1,j-1,arr),f(i+2,j,arr));
	int q2=arr[j]+min(f(i,j-2,arr),f(i+1,j-1,arr));
	
	return max(q1,q2);
}
int dpsol(int arr[])
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i>=j)
			dp[i][j]=0;
			else
			dp[i][j]=max((arr[i]+min(dp[i+1][j-1],dp[i+2][j])),(arr[j]+min(dp[i][j-2],dp[i+1][j-1])));
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n-1][n-1];
}
int dp_memo(int i,int j,int arr[])
{
	if(i>j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int q1=arr[i]+min(f(i+1,j-1,arr),f(i+2,j,arr));
	int q2=arr[j]+min(f(i,j-2,arr),f(i+1,j-1,arr));
	
	dp[i][j]=max(q1,q2);
	
	return dp[i][j];
}
int main()
{
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	//Recursive call f(0,n-1,arr);
	//cout<<dpsol(arr)<<endl;
	cout<<dp_memo(0,n-1,arr);
	return 0;
}
	
