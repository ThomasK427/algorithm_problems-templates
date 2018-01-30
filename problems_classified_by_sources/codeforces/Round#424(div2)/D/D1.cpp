#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
const int maxk = 2005;

LL a[maxn], b[maxk];

int main()
{
    int n, k;
    LL p;
    scanf("%d%d%lld", &n, &k, &p);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    for(int i = 1; i <= k; i++){
        scanf("%lld", b + i);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    LL ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= k - n + 1; i++){
        LL tmp = 0;
        for(int j = 1; j <= n; j++){
            tmp = max(tmp, abs(a[j] - b[i + j - 1]) + abs(b[i + j - 1] - p));
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
