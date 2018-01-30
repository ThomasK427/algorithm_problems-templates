#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n, k, a, b;
    cin >> n >> k;
    if(k == 0 || n == k){
        a = 0;
    }
    else{
        a = 1;
    }
    if(n >= 3 * k){
        b = 2 * k;
    }
    else{
        b = n - k;
    }
    cout << a << " " << b << endl;
    return 0;
}
