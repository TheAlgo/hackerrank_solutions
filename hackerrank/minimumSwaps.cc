#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	int arr[n];
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	m[arr[i]]=i;
}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==i+1)
		continue;
		else
		{
			int index=m[i+1];
			m[i+1]=i;
			m[arr[i]]=index;
			swap(arr[i],arr[index]);
			count++;
		}
	}
	cout<<count<<endl;
			
	
	return 0;
}
