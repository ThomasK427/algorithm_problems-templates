#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;

LL qpow(LL a, LL n, LL Q)
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
    LL inv2 = qpow(2, mod - 2, mod);
    LL N;
    cin >> N;
    cout << (qpow(3, N + 1, mod) - 1 + mod) % mod * inv2 % mod << endl;
    return 0;
}
