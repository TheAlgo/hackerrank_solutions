#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int k;
	cin>>k;
	string s;
	cin>>s;
	int i=0,j=0,maxLength=1;
	int counta=0,countb=0;
	char ch;
	for(int l=0;l<s.length();l++)
	{
		if(s[l]=='a')
		counta++;
		else
		countb++;
	}
	if(counta>=countb)
	ch='a';
	else ch='b';
	
	while(i<=j && j<s.length())
	{
		if(s[j]==ch)
		{
			maxLength=max(maxLength,j-i+1);
			j++;
			continue;
		}
		else
		{
			if(k>0)
			{
				j++;
				k--;
			}
			else
			{
			while(true)
			{
				if(k>0)
				break;
				if(s[i]==ch)
				{
				i++;
				continue;
				}
				else
				{
					k++;
					i++;
				}
			}
		}
			maxLength=max(maxLength,j-i+1);
		}
	}
		
	cout<<maxLength<<endl;
	return 0;
}
