#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int val[1001],wt[1001];
int knapsackRec(int W,int n)
{
	if(W==0||n==0)
	return 0;
	
	if(wt[n-1]>W)
	return knapsackRec(W,n-1);
	
	else
	return max(val[n-1]+knapsackRec(W-wt[n-1],n-1),knapsackRec(W,n-1));
}

int knapsackDP(int W,int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			
			if(wt[i-1]<=j)
			{
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
				
			}
			else 
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][W];
}


int main()
{
	int n,W;
	cin>>n>>W;
	for(int i=0;i<n;i++)
	cin>>wt[i];
	
	for(int j=0;j<n;j++)
	cin>>val[j];
	
	//cout<<knapsackRec(W,n);
	cout<<knapsackDP(W,n);
	return 0;
}
	
