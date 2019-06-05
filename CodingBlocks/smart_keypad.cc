#include<iostream>
using namespace std;
char t[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz","\0" };
void keypad(char *inp,char *out,int i,int j)
{
    if(inp[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit=inp[i]-'0';
    for(int k=0;t[digit][k]!='\0';k++)
    {
        out[j]=t[digit][k];
        keypad(inp,out,i+1,j+1);
    }
}
int main() {
    char s[20];
    cin>>s;
    char o[20];
    keypad(s,o,0,0);
	return 0;
}
