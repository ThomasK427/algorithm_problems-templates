#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 55;
const int maxm = 10000;

int cost[maxn];
int dp[maxm];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int n, t;
        scanf("%d%d", &n, &t);
        for(int i = 1; i <= n; i++){
            scanf("%d", cost + i);
        }
        dp[0] = 0;
        for(int i = 1; i <= t - 1; i++){
            dp[i] = -INF;
        }
        for(int i = 1; i <= n; i++){
            for(int j = t - 1; j >= cost[i]; j--){
                dp[j] = max(dp[j], dp[j - cost[i]] + 1);
            }
        }
        int ans = 0;
        for(int i = 1; i <= t - 1; i++){
            ans = max(ans, dp[i]);
        }
        for(int i = t - 1; i >= 1; i--){
            if(dp[i] == ans){
                printf("Case %d: %d %d\n", ++kase, ans + 1, i + 678);
                break;
            }
        }
    }
    return 0;
}
