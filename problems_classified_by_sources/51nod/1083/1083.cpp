#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 505;

int a[maxn][maxn];
LL dp[maxn][maxn];

int main()
{
    int N;
    for(int i = 0; i < maxn; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    while(~scanf("%d", &N)){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
        printf("%lld\n", dp[N][N]);
    }
    return 0;
}
