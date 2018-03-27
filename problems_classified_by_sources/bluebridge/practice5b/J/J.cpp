#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 305;

LL dp[maxn][maxn];

LL dfs(int n, int k){
    LL& ans = dp[n][k];
    if(ans >= 0){
        return ans;
    }
    ans = 0;
    if(n == 1 || k == 1){
        ans = 1;
    }
    else if(n < k){
        ans = dfs(n, n);
    }
    else if(n == k){
        ans = dfs(n, k - 1) + 1;
    }
    else{
        ans = dfs(n, k - 1) + dfs(n - k, k);
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", dfs(n, k));
    return 0;
}
