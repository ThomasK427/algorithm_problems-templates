/**
*从1和n开始计算最短路径数组
*对每个团设置一个虚拟节点M，M到团中任一节点距离为t，
*团中任一节点到M距离为0，然后用spfa算法计算最短路径数组即可
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;
const int maxm = 1000005;

vector<P> g[maxn + maxm];
LL d1[maxn + maxm], d2[maxn + maxm];
bool inQue[maxn + maxm];
int n, m;

void spfa(int src, LL* d){
    queue<int> que;
    for(int i = 1; i <= m + n; i++){
        d[i] = INF;
    }
    memset(inQue, false, sizeof(inQue));
    d[src] = 0;
    que.push(src);
    inQue[src] = true;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            if(d[v] > d[u] + g[u][i].second){
                d[v] = d[u] + g[u][i].second;
                if(!inQue[v]){
                    que.push(v);
                    inQue[v] = true;
                }
            }
        }
        inQue[u] = false;
    }
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n + m; i++){
            g[i].clear();
        }
        for(int i = 1; i <= m; i++){
            int t, s, idx = n + i;
            scanf("%d%d", &t, &s);
            for(int j = 1; j <= s; j++){
                int x;
                scanf("%d", &x);
                g[idx].push_back(P(x, t));
                g[x].push_back(P(idx, 0));
            }
        }
        spfa(1, d1);
        spfa(n, d2);
        LL ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans, max(d1[i], d2[i]));
        }
        if(ans == INF){
            printf("Case #%d: Evil John\n", ++kase);
            continue;
        }
        printf("Case #%d: %lld\n", ++kase, ans);
        bool isFirst = true;
        for(int i = 1; i <= n; i++){
            if(ans == max(d1[i], d2[i])){
                if(!isFirst){
                    putchar(' ');
                }
                isFirst = false;
                printf("%d", i);
            }
        }
        putchar('\n');
    }
    return 0;
}
