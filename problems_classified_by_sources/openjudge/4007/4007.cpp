#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn], t[maxn];
int dp[maxn][maxn];

int dist(){
    memset(dp, 0, sizeof(dp));
    int u = strlen(s + 1), v = strlen(t + 1);
    for(int i = 1; i <= u; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= v; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= u; i++){
        for(int j = 1; j <= v; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if(s[i] == t[j]){
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else{
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[u][v];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s", s + 1, t + 1);
        printf("%d\n", dist());
    }
    return 0;
}
