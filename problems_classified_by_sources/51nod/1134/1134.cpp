#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;

int ar[maxn];
int dp[maxn];

int main()
{
    int N;
    while(~scanf("%d", &N)){
        for(int i = 0; i < N; i++){
            scanf("%d", ar + i);
        }
        fill(dp, dp + N + 1, INF);
        for(int i = 0; i < N; i++){
            int p = lower_bound(dp, dp + N, ar[i]) - dp;
            dp[p] = ar[i];
        }
        printf("%d\n", lower_bound(dp, dp + N + 1, INF) - dp);
    }
    return 0;
}
