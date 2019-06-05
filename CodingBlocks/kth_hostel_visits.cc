#include<bits/stdc++.h>
using namespace std;

 class hostel {
    public:
        long long x, y;
        hostel(long long x, long long y) {
            this->x = x;
            this->y = y;
        }
        long long dist() {
            return x*x+y*y;
        }
        
        void print()
        {
        	cout<<dist()<<endl;
		}
};
class compare {
    public:
        bool operator()(hostel a, hostel b) {
            return a.dist() < b.dist();
    }
};
 
 int main()
{
	priority_queue< hostel, vector<hostel>, compare > pq;
	
	int n,k,q,x,y,l;
	cin>>n>>k;
	
	int count=0;
	hostel z(INT_MAX,INT_MAX);
	while(n--)
	{
		cin>>q;
		
		if(q==2)
		{
			hostel h=pq.top();
			h.print();
		}
		else{
		cin>>x>>y;
		hostel h(x,y);
			
		 if(count<k)
		{
			pq.push(h);
			count++;
		}
		else if(h.dist()<z.dist())
		{
			pq.pop();
			pq.push(h);
		}
		}
		z=pq.top();
	}
	return 0;
}
