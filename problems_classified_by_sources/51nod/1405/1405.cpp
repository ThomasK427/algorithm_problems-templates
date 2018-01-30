#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

vector<int> g[maxn];
long long cnt[maxn], up[maxn], down[maxn];
int N;

long long dfs(int k, int fa){
    long long& ans = cnt[k];
    ans = 1;
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            ans += dfs(v, k);
        }
    }
    return ans;
}

long long dfsUp(int k, int fa){
    long long& ans = up[k];
    ans = 0;
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            ans += dfsUp(v, k);
        }
    }
    return ans + cnt[k];
}

void dfsDown(int k, int fa){
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            down[v] = down[k] + up[k] + N - up[v] - cnt[v] * 2;
            dfsDown(v, k);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    dfsUp(1, -1);
    down[1] = 0;
    dfsDown(1, -1);
    for(int i = 1; i <= N; i++){
        printf("%lld\n", up[i] + down[i]);
    }
    return 0;
}
