#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	int n=s.length();
	stack<int> s1;
	for(int i=0;i<=n;i++)
	{
		s1.push(i+1);
		if(i==n || s[i]=='I')
		{
			while(!s1.empty())
			{
			cout<<s1.top();
			s1.pop();
			}
		}
	}
	cout<<endl;
}
	return 0;
}
		
			
