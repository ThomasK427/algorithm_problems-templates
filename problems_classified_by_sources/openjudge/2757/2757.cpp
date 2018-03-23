#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn], dp[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", ar + i);
    }
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < N; i++){
        *lower_bound(dp, dp + N, ar[i]) = ar[i];
    }
    printf("%d\n", lower_bound(dp, dp + N, INF) - dp);
    return 0;
}
