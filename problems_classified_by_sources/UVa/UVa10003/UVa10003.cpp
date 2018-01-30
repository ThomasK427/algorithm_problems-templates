#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 60;

int ar[maxn];
int L, n;
int dp[maxn][maxn];

int d(int i, int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    ans = INF;
    if(i + 1 == j){
        ans = 0;
    }
    for(int k = i + 1; k < j; k++){
        ans = min(ans, d(i, k) + d(k, j) + ar[j] - ar[i]);
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &L) && L){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
        }
        memset(dp, -1, sizeof(dp));
        ar[0] = 0;
        ar[n + 1] = L;
        printf("The minimum cutting is %d.\n", d(0, n + 1));
    }
    return 0;
}
