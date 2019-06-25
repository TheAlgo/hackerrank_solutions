#include<iostream>
using namespace std;
int main()
{
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	char arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>arr[i][j];
	}
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<m;j++)
		{
			if(s<0)
			{
				cout<<"No"<<endl;
				exit(0);
			}
			if(arr[i][j]=='.')
			{
			s=s-2;
			if(j!=m-1)
			s=s-1;
		}
			
			else if(arr[i][j]=='*')
			{
			s=s+5;
			if(j!=m-1)
			s=s-1;
		}
			
			else if(arr[i][j]=='#')
			{
				
				break;
			}
			//cout<<s<<" ";
		}
	}
	//cout<<endl;
	if(s>=k)
	{
	cout<<"Yes"<<endl;
	cout<<s<<endl;
}
	else
	cout<<"No"<<endl;
	return 0;
}
