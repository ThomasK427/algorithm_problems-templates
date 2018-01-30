#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxm = 10000;

struct Node{
    int num, tim;
}dp[maxn][maxm];

int cost[maxn];

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
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= t; j++){
                dp[i][j].num = 0;
                dp[i][j].tim = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= t - 1; j++){
                if(cost[i] > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    if(dp[i - 1][j].num > dp[i - 1][j - cost[i]].num + 1){
                        dp[i][j] = dp[i - 1][j];
                    }
                    else if(dp[i - 1][j].num < dp[i - 1][j - cost[i]].num + 1){
                        dp[i][j].num = dp[i - 1][j - cost[i]].num + 1;
                        dp[i][j].tim = dp[i - 1][j - cost[i]].tim + cost[i];
                    }
                    else if(dp[i - 1][j].tim >= dp[i - 1][j - cost[i]].tim + cost[i]){
                        dp[i][j] = dp[i - 1][j];
                    }
                    else{
                        dp[i][j].num = dp[i - 1][j - cost[i]].num + 1;
                        dp[i][j].tim = dp[i - 1][j - cost[i]].tim + cost[i];
                    }
                }
            }
        }
        printf("Case %d: %d %d\n", ++kase, dp[n][t - 1].num + 1, dp[n][t - 1].tim + 678);
    }
    return 0;
}
