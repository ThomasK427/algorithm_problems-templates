#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 50005;

struct Edge{
    int from, to, cost;
    friend bool operator<(const Edge& e1, const Edge& e2){
        return e1.cost > e2.cost;
    }
};

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
    if(m == n)return;
    if(-par[m] > -par[n]){
        par[m] += par[n];
        par[n] = m;
    }
    else{
        par[n] += par[m];
        par[m] = n;
    }
}

priority_queue<Edge> pq;

int main()
{
    int N, M;
    while(~scanf("%d%d", &N, &M)){
        init(N);
        while(!pq.empty()){
            pq.pop();
        }
        Edge e;
        for(int i = 0; i < M; i++){
            scanf("%d%d%d", &e.from, &e.to, &e.cost);
            pq.push(e);
        }
        long long ans = 0;
        int cnt = 0;
        for(int i = 0; i < M; i++){
            e = pq.top();
            pq.pop();
            if(Find(e.from) != Find(e.to)){
                ans += e.cost;
                Unite(e.from, e.to);
                cnt++;
                if(cnt == N - 1){
                    break;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}













