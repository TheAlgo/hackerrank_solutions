
#include<iostream>
#define ll long int
using namespace std;
void calculate(ll arr[],ll n,ll target)
{
	ll i=0,j=0;
	ll sum=arr[i];
	while(i!=n && j!=n)
	{
		//cout<<sum<<endl;
		if(sum>target)
		{
			sum-=arr[i];
			i++;
		}
		else if(sum<target)
		{
			j++;
			sum+=arr[j];
			
		}
		else
		{
			cout<<i+1<<" "<<j+1<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}
int main()
{	int t;
	cin>>t;
	while(t--)
	{
		ll n,target;
		cin>>n>>target;
		ll arr[n];
		for(ll i=0;i<n;i++)
		cin>>arr[i];
		calculate(arr,n,target);
		
	//code
}
	return 0;
}
