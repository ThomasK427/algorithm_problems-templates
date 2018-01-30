#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 25;

long long dp[maxn][maxn][maxn];

long long d(int i, int j, int k)
{
    if(dp[i][j][k] >= 0){
        return dp[i][j][k];
    }
    else{
        return d(i - 1, j - 1, k) + d(i - 1, j, k - 1) + d(i - 1, j, k) * (i - 2);
    }
}

void init()
{
    dp[1][1][1] = 1;
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            for(int k = 0; k < maxn; k++){
                if(i * j * k == 0){
                    dp[i][j][k] = 0;
                }
                else if(j > i || k > i || j + k > i + 1){
                    dp[i][j][k] = 0;
                }
                else if((i == j && k == 1) || (i == k && j == 1)){
                    dp[i][j][k] = 1;
                }
            }
        }
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        printf("%lld\n", d(n, l, r));
    }
    return 0;
}
