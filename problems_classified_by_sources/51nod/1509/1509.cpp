#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(LL a, LL b, LL c, LL L){
    LL ans = 0;
    for(LL z = 0; z <= L; z++){
        LL t = min(c + z - a - b, L - z);
        if(t >= 0){
            ans += (t + 2) * (t + 1) / 2;
        }
    }
    return ans;
}

int main()
{
    LL a, b, c, L;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &L);
    LL ans = (L + 3) * (L + 2) * (L + 1) / 6;
    ans -= f(a, b, c, L);
    ans -= f(b, c, a, L);
    ans -= f(c, a, b, L);
    printf("%lld\n", ans);
    return 0;
}
