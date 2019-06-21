#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
void find(string str,string temp)
{
	int len=str.size();
	
	for(int i=1;i<=len;i++)
	{
		string pref=str.substr(0,i);
		if(m[pref]==true)
		{
			if(i==len)
			{
				temp+=pref;
				cout<<temp<<endl;
				return ;
			}
			find(str.substr(i,len-i),temp+pref+" ");
		}
	}
	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string in;
		cin>>in;
		m[in]=true;
	}
	string str;
	cin>>str;
	find(str,"");
	return 0;
}
