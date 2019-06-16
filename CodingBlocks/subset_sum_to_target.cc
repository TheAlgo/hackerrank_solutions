#include<iostream>
#include<cstring>
using namespace std;
bool subsetsum(int n,int sum,int arr[])
{
	if(sum==0)
	return true;
	if(n==0 && sum!=0)
	return false;
	
	if(arr[n-1]>sum)
	return subsetsum(n-1,sum,arr);
	else
	{
		return subsetsum(n-1,sum-arr[n-1],arr)||subsetsum(n-1,sum,arr);
	}
}
int subset_memo(int n,int sum,int arr[],int dp[],int target)
{
	if(sum==0)
	return 1;
	if(n==0 && sum!=0)
	return 0;
	
	if(dp[sum]!=-1)
	return dp[sum];
	
	if(arr[n-1]>sum)
	dp[sum]=subset_memo(n-1,sum,arr,dp,target);
	
	else
	{
		dp[sum]=subset_memo(n-1,sum-arr[n-1],arr,dp,target)||subset_memo(n-1,sum,arr,dp,target);
	}
	return dp[sum];
}
bool subset_dp(int n,int sum,int arr[])
{
	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++) dp[i][0]=true;
	for(int j=0;j<=n;j++) dp[0][j]=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]>j)
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
		}
	}
	return dp[n][sum];
}
int main()
{
	int n,target;
	cin>>n>>target;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int dp[target+1];
	memset(dp,-1,sizeof(dp));
	//cout<<subsetsum(n,target,arr)<<endl;;
	if(subset_dp(n,target,arr))
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0;
}
