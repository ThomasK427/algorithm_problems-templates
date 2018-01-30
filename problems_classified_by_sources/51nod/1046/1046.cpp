#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
    LL A, B, C;
    while(~scanf("%lld%lld%lld", &A, &B, &C)){
        printf("%lld\n", qpow(A, B, C));
    }
    return 0;
}
