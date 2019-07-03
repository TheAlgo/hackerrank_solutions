#include<iostream>
using namespace std;

/*int dpsolve(int arr[],int index,int sum,int n)
{
    if(index>=n)
    {
        return sum;
    }
    if(dp[sum]!=-1 && dp[sum]>sum)
    return dp[sum];
    if(n==0)
    return 0;
    
    return dp[sum]=max(dpsolve(arr,index+2,sum+arr[index],n),dpsolve(arr,index+1,sum,n));
    
}*/
int dp(int arr[],int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return arr[0];
    int dp[n];
    for(int i=0;i<n;i++)
    dp[i]=arr[i];;
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-2]+dp[i],max(dp[i],dp[i-1]));
        
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    sum+=arr[i];
}
cout<<dp(arr,n)<<endl;

}
