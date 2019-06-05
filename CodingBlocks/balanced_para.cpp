#include<iostream>
#include<stack>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<char> st;
	int flag=1;
	for(int i=0;i<s.length();i++)
	{
		char c=s[i];
		if(c=='{'||c=='['||c=='(')
		st.push(c);
		
		else if(!st.empty())
		{
		if(c==')' && st.top()=='(')
		st.pop();
		
		else if(c=='}' && st.top()=='{')
		st.pop();
		
		else if(c==']' && st.top()=='[')
		st.pop();
		else
	{
		flag=0;
		break;
	}
		}
		else
		{
			flag=0;
			break;
		}
	
}
if(flag) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}

