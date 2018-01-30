#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void extgcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if(!b){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

LL inv(LL a, LL n)
{
    LL d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

int main()
{
    LL M, N;
    while(~scanf("%lld%lld", &M, &N)){
        printf("%lld\n", inv(M, N));
    }
    return 0;
}
