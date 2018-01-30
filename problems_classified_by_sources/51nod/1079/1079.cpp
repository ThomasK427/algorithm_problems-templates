#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 20;

LL a[maxn], m[maxn];

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

LL CRT(int n)
{
    LL M = 1;
    for(int i = 0; i < n; i++){
        M *= m[i];
    }
    LL ret = 0;
    for(int i = 0; i < n; i++){
        LL x, y;
        LL tm = M / m[i];
        extgcd(tm, m[i], x, y);
        ret = (ret + tm * x * a[i]) % M;
    }
    return (ret + M) % M;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", m + i, a + i);
    }
    printf("%lld\n", CRT(n));
    return 0;
}
