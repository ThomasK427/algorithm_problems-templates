#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxk = 10005;

int w[maxn], p[maxn];
int dp[maxn][maxk];

int main()
{
    int N, W;
    while(~scanf("%d%d", &N, &W)){
        for(int i = 1; i <= N; i++){
            scanf("%d%d", w + i, p + i);
        }
        for(int i = 0; i <= N; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= W; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= W; j++){
                if(w[i] <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + p[i]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        printf("%d\n", dp[N][W]);
    }
    return 0;
}
