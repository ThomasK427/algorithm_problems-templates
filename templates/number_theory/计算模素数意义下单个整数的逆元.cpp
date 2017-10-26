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

LL Inv(LL x){   //求模Q意义下的逆元，Q为素数
    return qpow(x, Q - 2);
}

int main()
{
    for(int i = 1; i <= 100; i++){
        printf("%lld\n", Inv(i));
    }
    return 0;
}
