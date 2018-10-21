#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 80 * 80 + 5;

LL gcd(LL a, LL b, LL& d, LL& x, LL& y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }else{
        gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

LL inv(LL a, LL Q){
    LL d, x, y;
    gcd(a, Q, d, x, y);
    return d == 1 ? (x + Q) % Q : -1;
}

LL n, m, K;
LL buf[100][100];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld%lld", &n, &m, &K);
        memset(buf, 0, sizeof(buf));
        for(int j = 1; j <= m; j++){
            buf[0][j] = 1;
        }
        for(int i = 1; i <= n; i++){
            buf[i][1] = 1;
            for(int j = 2; j <= m; j++){
                buf[i][j] = (buf[i][j - 1] + buf[i - 1][j]) % K;
            }
        }
        LL ans = n;
        for(LL i = 1; i <= n * m; i++){
            ans = ans * i % K;
        }
        ans = ans * inv(buf[n][m], K) % K;
        printf("%lld\n", ans);
    }
    return 0;
}
