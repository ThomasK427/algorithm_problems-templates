#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

int b[maxn];
LL dp[maxn][2];

int main()
{
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", b + i);
        }
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + b[i-1] - 1);
            dp[i][1] = max(dp[i-1][0] + b[i] - 1, dp[i-1][1] + abs(b[i] - b[i-1]));
        }
        printf("%lld\n", max(dp[n-1][0], dp[n-1][1]));
    }
    return 0;
}
