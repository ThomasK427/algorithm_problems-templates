#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

struct Node{
    int from, to, cost;
    friend bool operator<(const Node& n1, const Node& n2){
        return n1.cost > n2.cost;
    }
}E[maxn * maxn];

priority_queue<Node> q;

int par[maxn];

void init(int n)
{
    for(int i = 0; i <= n; i++){
        par[i] = -1;
    }
}

int Find(int x)
{
    while(par[x] >= 0){
        x = par[x];
    }
    return x;
}

void Unite(int x, int y)
{
    int m = Find(x), n = Find(y);
    if(m == n){
        return;
    }
    else if(-m < -n){
        par[n] += par[m];
        par[m] = n;
    }
    else{
        par[m] += par[n];
        par[n] = m;
    }
}

int Kruskal(int n)
{
    init(n);
    int low = q.top().cost, high = low;
    int cnt = 0;
    while(!q.empty()){
        Node nd = q.top();
        if(Find(nd.from) == Find(nd.to)){
            high = nd.cost;
        }
        else{
            high = nd.cost;
            Unite(nd.from, nd.to);
            cnt++;
            if(cnt == n - 1){
                break;
            }
        }
        q.pop();
    }
    if(cnt == n - 1){
        return high - low;
    }
    else{
        return INF;
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m) && (n + m)){
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &E[i].from, &E[i].to, &E[i].cost);
        }
        sort(E, E + m);
        reverse(E, E + m);
        int ans = INF;
        for(int i = 0; i <= m - n + 1; i++){
            while(!q.empty())q.pop();
            for(int j = i; j < m; j++){
                q.push(E[j]);
            }
            ans = min(ans, Kruskal(n));
        }
        if(ans == INF){
            puts("-1");
        }
        else{
            printf("%d\n", ans);
        }
    }
    return 0;
}
