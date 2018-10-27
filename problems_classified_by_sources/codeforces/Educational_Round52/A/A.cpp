#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        LL s, a, b, c;
        scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
        LL ans = s / c + s / c / a * b;
        printf("%lld\n", ans);
    }
    return 0;
}
