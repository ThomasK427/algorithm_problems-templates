#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int par[maxn];
vector<int> g[maxn];
int N, T;

int dp(int u){
    if(g[u].size() == 0){
        return 1;
    }
    vector<int> v;
    for(int i = 0; i < g[u].size(); i++){
        v.push_back(dp(g[u][i]));
    }
    sort(v.begin(), v.end());
    int c = (int(g[u].size()) * T - 1) / 100 + 1;
    int ans = 0;
    for(int i = 0; i < c; i++){
        ans += v[i];
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &N, &T) && (N || T)){
        memset(par, 0, sizeof(par));
        for(int i = 0; i <= N; i++){
            g[i].clear();
        }
        for(int i = 1; i <= N; i++){
            scanf("%d", par + i);
            g[par[i]].push_back(i);
        }
        printf("%d\n", dp(0));
    }
    return 0;
}
