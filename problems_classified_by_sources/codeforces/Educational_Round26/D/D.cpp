#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
typedef long long LL;

struct Node{
    int u, v;
}s[maxn], dp[maxn][maxn];

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k)){
        LL x;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &x);
            int cnt1 = 0;
            while(x % 2 == 0){
                x /= 2;
                cnt1++;
            }
            int cnt2 = 0;
            while(x % 5 == 0){
                x /= 5;
                cnt2++;
            }
            s[i].u = cnt1;
            s[i].v = cnt2;
        }
        for(int j = 0; j <= k; j++){
            dp[0][j] = {0, 0};
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(min(dp[i-1][j].u, dp[i-1][j].v) > min(dp[i-1][j-1].u + s[i].u, dp[i-1][j-1].v + s[i].v)){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                    dp[i][j].u += s[i].u;
                    dp[i][j].v += s[i].v;
                }
            }
        }
        printf("%d\n", min(dp[n][k].u, dp[n][k].v));
    }
    return 0;
}
