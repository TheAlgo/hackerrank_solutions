#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,d,index=0;
	cin>>n>>d;
	vector<int> arr (n);
	for(int i=0;i<n;i++)
	{
		index=i-d;
		if(index<0)
		index=index+n;
		cin>>arr[index];
	}
	for(int j=0;j<n;j++)
	cout<<arr[j]<<" ";
	return 0;
}
