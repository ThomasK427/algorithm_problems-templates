#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    LL k, d, t;
    scanf("%lld%lld%lld", &k, &d, &t);
    d = (k + d - 1) / d * d;
    t *= 2;
    LL p = d + k;
    double ans = t / p * d;
    t %= p;
    if(2 * k >= t){
        ans += double(t) / 2;
    }
    else{
        t -= 2 * k;
        ans += k + t;
    }
    printf("%.1f\n", ans);
    return 0;
}
