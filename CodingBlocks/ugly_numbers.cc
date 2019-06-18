
#include <iostream>
using namespace std;
long long int nthugly(long long int n)
{
    long long int dp[n];
    long long int i2=0;
    long long int i3=0;
    long long int i5=0;
    long long int mul_2=2;
    long long int mul_3=3;
    long long int mul_5=5;
    long long int next_no=1;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        next_no=min(mul_2,min(mul_3,mul_5));
        dp[i]=next_no;
        if(next_no==mul_2)
        {
            i2=i2+1;
            mul_2=2*dp[i2];
        }
        if(next_no==mul_3)
        {
            i3=i3+1;
            mul_3=3*dp[i3];
        }
        if(next_no==mul_5)
        {
            i5=i5+1;
            mul_5=5*dp[i5];
        }
    }
   /* for(int i=0;i<n;i++)
    cout<<dp[i]<<" ";
    cout<<endl;*/
   return next_no;
}
int main() {
   int t;
   cin>>t;
   for(int i=0; i<t; i++){
      long long int n;
      cin>>n;
      cout<<nthugly(n)<<endl;
   }
}
