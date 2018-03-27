#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 305;

LL dp[maxn][maxn][maxn];

LL dfs(int n, int k, int m){
    LL& ans = dp[n][k][m];
    if(ans >= 0){
        return ans;
    }
    ans = 0;
    if(k == 1){
        ans = 1;
    }
    else{
        for(int i = m; n - i >= i; i++){
            ans += dfs(n - i, k - 1, i);
        }
        ans++;
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", dfs(n, k, 1));
    return 0;
}
