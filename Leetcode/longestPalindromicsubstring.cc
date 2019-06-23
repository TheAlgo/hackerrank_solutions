#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
string longest(string s)
{
	
	int len=s.length();
	int dp[len][len];
	memset(dp,0,sizeof(dp));
	int maxLength=0,start=0;
	for(int i=0;i<len;i++)
	dp[i][i]=1;
	
	for(int i=0;i<len-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=1;
			maxLength=2;
			start=i;
		}
	}	
	for(int k=3;k<=len;k++)
	{
		for(int i=0;i<len-k+1;i++)
		{
			int j=i+k-1;
			if(dp[i+1][j-1]==1 && s[i]==s[j])
			{
				dp[i][j]=1;
				if(k>maxLength)
				{
				maxLength=k;
				start=i;
			}
			}
		}
	}
	return s.substr(start,maxLength);
}

int main()
{
	string s;
	cin>>s;
	cout<<longest(s)<<endl;
	return 0;
}
