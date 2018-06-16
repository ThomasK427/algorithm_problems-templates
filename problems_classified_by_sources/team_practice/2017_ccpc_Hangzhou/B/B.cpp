#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const LL Q = 998244353;
const int maxn = 1005;

LL qpow(LL a, LL n){
    LL base = a % Q, res = 1;
    while(n){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

LL p[maxn], q[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            scanf("%lld%lld", p + i, q + i);
        }
        LL ans = 1;
        for(int i = 1; i <= m; i++){
            ans = ans * qpow(p[i], q[i] - 1) % Q;
            ans = ans * ((p[i] * q[i] % Q + (p[i] - q[i] + Q) % Q) % Q) % Q;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
