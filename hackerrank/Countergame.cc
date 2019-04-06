#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
bool isPowerOfTwo (long x) 
{ 
  
  return x && (!(x&(x-1))); 
} 
int inverse(int x)
{
    if(x==0)
    return 1;
    else
    return 0;
}
long highestPowerof2(long n) 
{ 
   long p = (long)log2(n); 
   return (long)pow(2, p);  
} 
string counterGame(long n) {
    int flag=0;
    while(n!=1)
    {
        if(isPowerOfTwo(n))
        {
            n=n/2;
            flag=inverse(flag);
        }
        else
        {
           
            n=n-highestPowerof2(n);
            flag=inverse(flag);
        }
    }
    if(flag)
    return "Louise";
    else
    return "Richard";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
