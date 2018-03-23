#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 505;
const int maxk = 105;
const int Q = 100000;

int ar[maxk], br[maxk];
int dp[maxn][maxm];

int main()
{
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 1; i <= K; i++){
        scanf("%d%d", ar + i, br + i);
    }
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 1; i <= K; i++){
        for(int j = N; j >= ar[i]; j--){
            for(int k = M - 1; k >= br[i]; k--){
                dp[j][k] = max(dp[j][k], dp[j - ar[i]][k - br[i]] + Q - br[i]);
            }
        }
    }
    int C = (dp[N][M - 1] == 0 ? 0 : dp[N][M - 1] / Q + 1);
    int R = M - (C * Q - dp[N][M - 1]);
    printf("%d %d\n", C, R);
    return 0;
}
