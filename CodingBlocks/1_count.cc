#include<iostream>
using namespace std;
int arr[1000001];
int n,k;
void kflip()
{
	int max=-1;
	int l=0,r=0,start=0,end=0,z=0;
	while(l<=r && r!=n)
	{
		if(arr[r]==1)
		{
			int c=r-l+1;
			if(c>max)
			{
				max=c;
				start=l;
				end=r;
			}
		}
		else if(arr[r]==0)
		{int c;
			if(z<=k)
			{
				z=z+1;
				c=r-l+1;
				
			}
			
			while(z>k)
			{
				if(arr[l]==0) z--;
				l++;
			}
			//z++;
			c=r-l+1;
		if(c>max)
			{
				max=c;
				start=l;
				end=r;
			}
	}
		r++;
	
}
cout<<max<<endl;
cout<<start<<" "<<end<<endl;
				
}
int main()
{
	
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	kflip();
	return 0;
}
