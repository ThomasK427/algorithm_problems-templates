#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

int a[maxn][maxn];
int dp[maxn][maxn];
int N;

int sum(int i, int j)
{
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    if(i == N){
        ans = a[i][j];
    }
    else{
        ans = max(sum(i + 1, j), sum(i + 1, j + 1)) + a[i][j];
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &N)){
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= i; j++){
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", sum(1, 1));
    }
    return 0;
}
