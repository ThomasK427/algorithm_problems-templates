#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n, p2, p3;
    scanf("%lld%lld%lld", &n, &p2, &p3);
    LL ans = 5000000000000000000;
    for(LL a = 0; a <= 5 && 2 * a <= n; a++){
        LL b = (n - 2 * a + 2) / 3;
        ans = min(ans, a * p2 + b * p3);
    }
    for(LL b = 0; b <= 5 && 3 * b <= n; b++){
        LL a = (n - 3 * b + 1) / 2;
        ans = min(ans, a * p2 + b * p3);
    }
    printf("%lld\n", ans);
    return 0;
}
