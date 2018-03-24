#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn], t[maxn];
int dp[maxn][maxn];

int main()
{
    while(~scanf("%s%s", s + 1, t + 1)){
        int m = strlen(s + 1), n = strlen(t + 1);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}
