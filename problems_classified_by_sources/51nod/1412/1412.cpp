#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1000000007;
const int maxh = 20;
const int maxn = 2005;

int L[maxh], R[maxh];
LL dp[maxh][maxn];
LL ans[maxn];

int main()
{
    L[0] = 0;
    L[1] = 1;
    R[1] = 1;
    for(int i = 2; i <= 16; i++){
        L[i] = L[i - 1] + L[i - 2] + 1;
        R[i] = (1 << i) - 1;
    }
    dp[1][1] = 1;
    dp[1][0] = 1;
    ans[1] = 1;
    for(int i = 2; i <= 15; i++){
        for(int j = L[i]; j <= min(R[i], 2000); j++){
            dp[i][j] = 0;
            for(int k = L[i - 2]; k <= j - 1 - L[i - 2]; k++){
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * dp[i - 1][j - k - 1] % Q + dp[i - 1][k] * dp[i - 2][j - k - 1] % Q
                            + dp[i - 2][k] * dp[i - 1][j - k - 1] % Q) % Q;
            }
            ans[j] = (ans[j] + dp[i][j]) % Q;
        }
    }
    int n;
    scanf("%d", &n);
    printf("%lld\n", ans[n]);
    return 0;
}
