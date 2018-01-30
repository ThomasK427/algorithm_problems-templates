#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;

LL qpow(LL a, LL n){
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

LL A(LL n, LL m){
    LL res = 1;
    for(LL i = 0; i < m; i++){
        res = res * (n - i) % Q;
    }
    return res;
}

int main()
{
    LL n, m;
    scanf("%lld%lld", &n, &m);
    if(n < m){
        puts("0");
    }
    else{
        printf("%lld\n", A(n, m) * qpow(m, n - m) % Q);
    }
    return 0;
}
