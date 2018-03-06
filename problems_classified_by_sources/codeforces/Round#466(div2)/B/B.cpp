#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    LL n, k, A, B;
    scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
    LL x = n, ans = 0;
    if(k == 1){
        ans = (x - 1) * A;
    }
    else{
        while(x > 1){
            if(x % k == 0){
                ans += min((x - x / k) * A, B);
                x /= k;
            }
            else{
                LL y = max(1LL, x / k * k);
                ans += (x - y) * A;
                x = y;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
