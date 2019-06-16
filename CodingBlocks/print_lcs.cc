#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001][1001];
string st1,st2,st3;
int lcs(int m,int n,int l)
{
	//for(int i=0;i<=m;i++) dp[i][0][0]=0;
	//for(int j=0;j<=n;j++) dp[0][j][0]=0;
	//for(int k=0;k<=l;k++) dp[0][0][k]=0;
	
	for(int x=1;x<=m;x++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int z=1;z<=l;z++)
			{
				
			if(st1[x-1]==st2[y-1] && st2[y-1]==st3[z-1])
			dp[x][y][z]=1+dp[x-1][y-1][z-1];
			else
			dp[x][y][z]=max(dp[x-1][y][z],max(dp[x][y-1][z],dp[x][y][z-1]));
		}
	}
}
	
	/*for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	
	return dp[m][n][l];
}
/*void print(int m,int n)
{
	int size=lcs(m,n);
	string str="";
	int k=size-1;
	int i=m,j=n;
	while(i!=0 && j!=0 && k>0)
	{
		int c=dp[i][j];
		if(dp[i-1][j]==dp[i][j-1] && c==dp[i-1][j])
		j=j-1;
		
		else if(dp[i-1][j]==dp[i][j-1])
		{
			//lcs[k--]=st1[i-1];
			str+=st1[i-1];
			i=i-1;
			j=j-1;
		}
		else if(dp[i-1][j]==c)
		i=i-1;
		
		else if(dp[i][j-1]==c)
		j=j-1;
	}
	//for(int j=0;j<size;j++)
	reverse(str.begin(),str.end());
	cout<<str;
}*/



int main()
{
	cin>>st1>>st2>>st3;
	int m=st1.length();
	int n=st2.length();
	int l=st3.length();
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=l;k++)
			dp[i][j][k]=0;
		}
	}
	//memset(dp,0,sizeof(dp));
	cout<<lcs(m,n,l)<<endl;
	return 0;
}
	
