#include<iostream>
#include<vector>
#include<algorithm>
#
using namespace std;
long n;
long checkPossible(vector<long> machines,long goal,long days)
{
    
    for(int a:machines)
    {
        goal=goal-(days/a);
    }
    return goal;
}
// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    sort(machines.begin(),machines.end());
    long max=machines[n-1]*goal;
    long min=1,mid;
    //cout<<max<<endl;
    while(min!=max)
    {
        mid=(min+max)/2;
        
        long a=checkPossible(machines,goal,mid);
    //  cout<<mid<<endl;
        
        if(a>0)
        min=mid+1;
        else if(a<=0)
        max=mid;
    }
   
   return min;
  
}
int main()
{
    long goal;
    vector<long> machines;
    cin>>n>>goal;
    for(long i=0;i<n;i++)
    {
        long a;
        cin>>a;
        machines.push_back(a);
    }
    cout<<minTime(machines,goal);
    return 0;
}
    
    
