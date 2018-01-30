#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

vector<int> g[maxn];
int dp[maxn][3];
bool used[maxn];
int N;

void d(int u){
    used[u] = true;
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = N;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!used[v]){
            d(v);
            dp[u][0] += min(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][2];
            dp[u][2] = min(dp[u][2], dp[v][0] - dp[v][2]);
        }
    }
    dp[u][2] += dp[u][1];
}

int main()
{
    //freopen("test.txt", "r", stdin);
    while(~scanf("%d", &N)){
        for(int i = 0; i <= N; i++){
            g[i].clear();
        }
        memset(dp, 0, sizeof(dp));
        memset(used, false, sizeof(used));
        int a, b;
        for(int i = 1; i <= N - 1; i++){
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        d(1);
        printf("%d\n", min(dp[1][0], dp[1][2]));
        scanf("%d", &N);
        if(N < 0){
            break;
        }
    }
    return 0;
}
