#include<iostream>
using namespace std;
bool isSafe(int arr[][12],int i,int j,int n)
{
	for(int k=0;k<i;k++)
	{
		if(arr[k][j]==1)
		{
		return false;
		}
	}
	int x=i,y=j;
	while(x>=0 && y>=0)
	{
		if(arr[x][y]==1)
		{
		return false;
		}
		x--;y--;
	}
	 x=i,y=j;
	while(x>=0 && y<n)
	{
		if(arr[x][y]==1)
		{
		return false;
		}
		x--;y++;
	}
	return true;
}
bool solve(int arr[][12],int i,int n,int &count)
{
	if(i==n)
	{
		++count;
		//Printing the solutions of the nqueen problem
		/*for(int l=0;l<n;l++)
		{
			for(int m=0;m<n;m++)
			{
				if(arr[l][m]==1)
				cout<<"Q";
				else
				cout<<"_";
			}
			cout<<endl;
		}*/

		return false;
	}
	for(int j=0;j<n;j++)
	{
		
		if(isSafe(arr,i,j,n))
		{
			arr[i][j]=1;
			bool next=solve(arr,i+1,n,count);
			if(next)
			{
				return true;
			}
			arr[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int arr[n][12]={0};
	int count=0;
	solve(arr,0,n,count);
	cout<<count<<endl;
	return 0;
}
	
