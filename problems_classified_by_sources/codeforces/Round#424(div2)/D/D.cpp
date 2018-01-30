#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
const int maxk = 2005;

LL a[maxn], b[maxk];
LL dp[maxn][maxk];

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
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= k; j++){
            if(i == j){
                dp[i][j] = max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p));
            }
            else{
                dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p)));
            }
        }
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = n; i <= k; i++){
        ans = min(ans, dp[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}
