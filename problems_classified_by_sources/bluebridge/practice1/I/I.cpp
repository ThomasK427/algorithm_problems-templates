#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

vector<int> g[maxn];
int bit[maxn], l[maxn], r[maxn], ans[maxn];
int n, p;

int lowbit(int x){
    return x & (-x);
}

int sum(int id){
    int res = 0;
    while(id > 0){
        res += bit[id];
        id -= lowbit(id);
    }
    return res;
}

void add(int id){
    while(id <= n){
        bit[id]++;
        id += lowbit(id);
    }
}

int cnt = 0;

void dfs(int k, int fa){
    l[k] = ++cnt;
    for(int i = 0; i < g[k].size(); i++){
        if(g[k][i] != fa){
            dfs(g[k][i], k);
        }
    }
    r[k] = cnt;
}

int main()
{
    scanf("%d%d", &n, &p);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(p, -1);
    for(int i = 1; i <= n; i++){
        ans[i] = sum(r[i]) - sum(l[i]);
        add(i);
    }
    for(int i = 1; i <= n; i++){
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
