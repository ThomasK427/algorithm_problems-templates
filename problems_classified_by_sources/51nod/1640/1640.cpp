#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int par[maxn];

void init(int n){
    for(int i = 0; i <= n; i++){
        par[i] = -1;
    }
}

int Find(int x){
    while(par[x] >= 0){
        x = par[x];
    }
    return x;
}

int Unite(int x, int y){
    int m = Find(x), n = Find(y);
    if(m != n){
        if(-par[m] > -par[n]){
            par[m] += par[n];
            par[n] = m;
        }
        else{
            par[n] += par[m];
            par[m] = n;
        }
    }
}

struct Edge{
    int from, to, cost;
    Edge(){}
    Edge(int a, int b, int c):from(a), to(b), cost(c){}
};

struct cmp1{
    bool operator()(const Edge& a, const Edge& b){
        return a.cost < b.cost;
    }
};

struct cmp2{
    bool operator()(const Edge& a, const Edge& b){
        return a.cost > b.cost;
    }
};

priority_queue<Edge, vector<Edge>, cmp2> q1;
priority_queue<Edge, vector<Edge>, cmp1> q2;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        q1.push(Edge(a, b, c));
    }
    init(N);
    int cnt = 0;
    cout << "#: " << endl;
    while(!q1.empty()){
        Edge e = q1.top();
        cout << e.cost << endl;
        q1.pop();
        q2.push(e);
        if(Find(e.from) != Find(e.to)){
            Unite(e.from, e.to);
            cnt++;
            if(cnt == N - 1){
                break;
            }
        }
    }
    long long ans = 0;
    init(N);
    cnt = 0;
    cout << "#: " << endl;
    while(!q2.empty()){
        Edge e = q2.top();
        cout << e.cost << endl;
        q2.pop();
        if(Find(e.from) != Find(e.to)){
            Unite(e.from, e.to);
            cnt++;
            ans += e.cost;
            if(cnt == N - 1){
                break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
