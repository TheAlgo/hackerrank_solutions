
#include<iostream>
using namespace std;
int main() {
    long long n,first,second,third;
    cin>>n;
    if(n%2==0)
    {
        first=(n/2)*(n/2)-1;
        second=n;
        third=(n/2)*(n/2)+1;
    }
    else
    {
        long long a=(n+1)/2;
         long long b=(n-1)/2;
        first=a*a-b*b;
        second=2*a*b;
        third=a*a+b*b;
    }
    if(first>0 && second>0 && third>0)
    {
    if(n==first && n!=0)
    cout<<second<<" "<<third;
    else if(n==second && n!=0)
    cout<<first<<" "<<third;
    else
    cout<<-1;
}
else
cout<<-1;
	return 0;
}
