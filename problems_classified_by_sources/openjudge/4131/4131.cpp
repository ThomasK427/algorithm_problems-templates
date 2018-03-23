#include <bits/stdc++.h>
using namespace std;
const int maxn = 3500;
const int maxm = 13000;

int w[maxn], d[maxn], dp[maxm];

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d%d", w + i, d + i);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = M; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    }
    printf("%d\n", dp[M]);
    return 0;
}
