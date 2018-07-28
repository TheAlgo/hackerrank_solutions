#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N , int num) {
    int expo_power = pow(num,N);
    if(expo_power==X)
        return 1;
    else if(expo_power>X)
        return 0;
    else
    return powerSum(X,N,num+1)+powerSum(X-expo_power,N,num+1);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N , 1);

    fout << result << "\n";

    fout.close();

    return 0;
}
