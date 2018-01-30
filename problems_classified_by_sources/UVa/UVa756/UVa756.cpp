//#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long LL;

LL ar[5], br[5];

LL extgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        LL r = extgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

LL CRT(LL* a, LL* m, int n)
{
    LL M = 1;
    for(int i = 0; i < n; i++){
        M *= m[i];
    }
    LL ret = 0;
    for(int i = 0; i < n; i++){
        LL x, y;
        LL tmp = M / m[i];
        extgcd(tmp, m[i], x, y);
        ret = (ret + tmp * x * a[i]) % M;
    }
    return (ret + M) % M;
}

int main()
{
    LL p, e, i, d;
    int kase = 0;
    while((~scanf("%lld%lld%lld%lld", &p, &e, &i, &d)) && !(p == -1 && e == -1 && i == -1 && d == -1)){
        ar[0] = (p % 23 - d % 23 + 23) % 23;
        br[0] = 23;
        ar[1] = (e % 28 - d % 28 + 28) % 28;
        br[1] = 28;
        ar[2] = (i % 33 - d % 33 + 33) % 33;
        br[2] = 33;
        LL ans = CRT(ar, br, 3);
        if(ans == 0){
            ans = 23 * 28 * 33;
        }
        printf("Case %d: the next triple peak occurs in %lld days.\n", ++kase, ans);
    }
    return 0;
}
