#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 505;

LL g[maxn][maxn];
LL s[maxn][maxn];

LL sum(int low, int high, int idx)
{
    return s[high][idx] - s[high][idx-1] - s[low-1][idx] + s[low-1][idx-1];
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int M, N;
    scanf("%d%d", &N, &M);
    memset(g, 0, sizeof(g));
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            scanf("%lld", &g[i][j]);
            s[i][j] = g[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
        }
    }
    LL ans = 0;
    for(int low = 1; low <= M; low++){
        for(int high = low; high <= M; high++){
            LL maxSum = 0, thisSum = 0;
            for(int i = 1; i <= N; i++){
                thisSum += sum(low, high, i);
                maxSum = max(maxSum, thisSum);
                thisSum = max(thisSum, 0LL);
            }
            ans = max(ans, maxSum);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
