#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n <= 2){
        cout << n << endl;
    }
    else if(n & 1){
        cout << n * (n - 1) * (n - 2) << endl;
    }
    else if(n % 6 == 0){
        cout << (n - 1) * (n - 2) * (n - 3) << endl;
    }
    else{
        cout << n * (n - 1) * (n - 3) << endl;
    }
    return 0;
}
