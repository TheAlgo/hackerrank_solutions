#include<iostream>
#include<climits>
using namespace std;
int findmin(int arr[],int n)
{
	
	if(arr[0]==0||n==0)
	return INT_MAX;
	
	int jumps[n];
	jumps[0]=0;
	for(int i=1;i<n;i++)
	{
		jumps[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(i<=j+arr[j] && jumps[j]!=INT_MAX)
			{
				jumps[i]=min(jumps[i],jumps[j]+1);
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<jumps[i]<<" ";
	cout<<endl;
	return jumps[n-1];
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		cout<<findmin(arr,n)<<endl;
	}
	return 0;
}
