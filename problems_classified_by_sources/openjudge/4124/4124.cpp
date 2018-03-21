#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 20;

int g[maxn][maxn];
int d[1 << maxn][maxn];
int N;

int dfs(int S, int last){
    if(d[S][last] < INF){
        return d[S][last];
    }
    else{
        for(int i = 1; i < N - 1; i++){
            if((S & (1 << i)) && (i != last)){
                d[S][last] = min(d[S][last], dfs(S ^ (1 << last), i));
            }
        }
        return d[S][last];
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &g[i][j]);
        }
    }
    memset(d, INF, sizeof(d));
    int ans = INF, S = (1 << N) - 1;
    for(int i = 1; i < N - 1; i++){
        d[1 | (1 << i)][i] = g[0][i];
    }
    for(int i = 1; i < N - 1; i++){
        ans = min(ans, dfs(S ^ (1 << i), i) + g[i][N - 1]);
    }
    printf("%d\n", ans);
    return 0;
}
