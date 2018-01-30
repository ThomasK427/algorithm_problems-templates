#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 10;

LL qpow(LL a, LL n)
{
    LL base = a % Q, res = 1;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

int main()
{
    LL N;
    cin >> N;
    cout << qpow(N, N) << endl;
    return 0;
}
