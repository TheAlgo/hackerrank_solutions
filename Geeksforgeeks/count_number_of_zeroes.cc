#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int i=0,j=n-1,flag=0;
	
	while(i<=j)
	{
		int mid=(i+j)/2;
		//cout<<mid<<endl;
		
		if((mid==0 && arr[mid]==0 )|| (arr[mid]==0 && arr[mid-1]==1))
		{
			cout<<n-mid<<endl;
			flag=1;
			break;
		}
		
		else if(arr[mid]==1)
		{
			i=mid+1;
			continue;
		}
	
		else
		{
			j=mid-1;
			continue;
		}
	}
if(flag==0)
cout<<flag<<endl;
}
return 0;
}
