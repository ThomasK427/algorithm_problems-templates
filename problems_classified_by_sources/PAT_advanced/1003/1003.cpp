#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 505;

int g[maxn][maxn], cost[maxn][maxn];
int num[maxn], d[maxn], cnt[maxn];
bool used[maxn];

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 0; i < n; i++){
        scanf("%d", num + i);
    }
    memset(g, INF, sizeof(g));
    memset(d, INF, sizeof(d));
    memset(cost, INF, sizeof(cost));
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++){
        cost[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = c;
        cost[a][b] = c;
    }
    d[s] = 0;
    cnt[s] = 1;
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }
        used[v] = true;
        for(int j = 0; j < n; j++){
            if(d[v] + g[v][j] < d[j]){
                d[j] = d[v] + g[v][j];
                cnt[j] = cnt[v];
            }
            else if(d[v] + g[v][j] == d[j]){
                cnt[j] += cnt[v];
            }
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cost[i][t] != INF){
            ans += num[i];
        }
    }
    printf("%d %d\n", cnt[t], ans);
    return 0;
}
