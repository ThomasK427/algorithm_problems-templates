#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

vector<int> g[maxn], h[maxn];
int par[maxn];

int Find(int x){
    return x == par[x] ? x : par[x] = Find(par[x]);
}

void Unite(int x, int y){
    int a = Find(x), b = Find(y);
    if(a == b){
        return;
    }
    par[a] = b;
}

bool judge(vector<int>& v){
    if(v.size() < 3){
        return false;
    }
    for(int i = 0; i < v.size(); i++){
        if(g[v[i]].size() != 2){
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        Unite(a, b);
    }
    for(int i = 1; i <= n; i++){
        h[Find(i)].push_back(i);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(judge(h[i])){
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}
