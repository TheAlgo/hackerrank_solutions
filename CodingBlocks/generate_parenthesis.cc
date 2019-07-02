#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string s)
{
	
	int len=s.length();
	if(len==0||len==1)
	return false;
	stack<char> st;
	for(int i=0;i<len;i++)
	{
		//if(!st.empty())
		//cout<<st.top()<<endl;
		if(s[i]=='(')
		{
			//cout<<"jhb"<<endl;;
		st.push(s[i]);
		}
		else
		{
			if((!st.empty()) && st.top()=='(')
			{
				//cout<<"popped"<<endl;
				st.pop();
			}
			else
			return false;
		}
	}
	
	return st.empty();
}
void solve(int index,int n,string s)
{
	if(index==2*n)
	{
		if(isBalanced(s))
		cout<<s<<endl;
	return;
}
solve(index+1,n,s+')');
solve(index+1,n,s+'(');
}



int main()
{
	int n;
	cin>>n;
	solve(0,n,"");
	/*if(isBalanced("()()")) 
	cout<<"hbhbh"<<endl;
	else
	cout<<"Not possible"<<endl;*/
	return 0;
}
