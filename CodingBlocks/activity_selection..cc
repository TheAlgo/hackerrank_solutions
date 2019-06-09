#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
struct cmpr{
bool operator()(pair<int,int> l, pair<int,int> r){
return l.second < r.second;
}
}cmp;
int main(){
int n,s,e,res;


res = 1;
vector<pair<int,int> > activity;
scanf("%d",&n);
for(int i = 0;i<n;i++){
scanf("%d %d",&s,&e);
activity.push_back(make_pair(s-e,s+e));
}
//Sort the activities according to their finish time
sort(activity.begin(),activity.end(),cmp);
//fin denotes the finish time of the choosen activity
//i.e. activity with least finish time
int fin = activity[0].second;
for(int i = 1;i<activity.size();i++){
//To find the next compatible activity with
//least finish time
//Find the first activity whose start time
//is more than finish time of previous activity
if(activity[i].first >= fin){
//update the finish time as the finish time
//of this activity
fin = activity[i].second;
//Since we have choosen a new activity,
//increment the count by 1
res++;
}
}
printf("%d\n",n-res);

return 0;
}
