
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a,Interval b)
{
    if(a.start>b.start)
    return false;
    
    else if(a.start<b.start)
    return true;
    
    else
    {
        if(a.end>b.end)
        return false;
        else
        return true;
    }
}
vector<Interval> Solution::merge(vector<Interval> &A) {
   vector<Interval> arr;
   arr=A;
   sort(arr.begin(),arr.end(),compare);
   stack<Interval> s;
   s.push(arr[0]);
   int i=1;
   while(i<arr.size())
   {
       Interval test=arr[i++];
       if(s.empty())
       s.push(test);
       else
       {
       Interval t=s.top();
       if(test.start>=t.start && test.start<=t.end && test.end>t.end)
       {
           Interval n(t.start,test.end);
           s.pop();
           s.push(n);
       }
       else if(test.start>t.end)
       {
           s.push(test);
       }
       else if(test.start>=t.end && test.start<=t.end && test.end>=t.start && test.end<=t.end)
       continue;
       }
   }
   vector<Interval> ans;
   while(!s.empty())
   {
       ans.push_back(s.top());
       s.pop();
   }
   sort(ans.begin(),ans.end(),compare);
   return ans;
   
}
