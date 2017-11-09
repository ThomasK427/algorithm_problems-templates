/**
*2015年ACM_ICPC沈阳站M题Meeting HDU5521
*
*从1和n开始以广度优先的方式计算最短距离数组
*每次弹出到1或n距离最短的点，遍历此点能到达的团
*将团中最短距离更新的点压入优先队列
*这样会把一个点多次压入到优先队列中
*但弹出时只需处理最后压入的一个即可
*由于对同一个点后压入优先队列中的结点距离一定比先压入的结点距离小
*最后压入的点最先弹出，标记一下可以使先压入的点弹出时不去处理
*由于团中点的距离相同，只需让最先到达的团中节点更新团中其他节点到1或n的距离即可
*每个团只需遍历一次
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;
const int maxm = 1000005;

struct Node{
    int idx, dist;
    Node(){}
    Node(int i, int d):idx(i), dist(d){}
    friend bool operator<(const Node& a, const Node& b){
        return a.dist > b.dist;
    }
};

int t[maxm];
int s[maxm];
vector<int> g[maxm];
vector<int> h[maxn];
bool vis1[maxn];
bool vis2[maxm];
LL d1[maxn];
LL d2[maxn];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int n, m, x;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++){
            h[i].clear();
        }
        for(int i = 0; i <= m; i++){
            g[i].clear();
        }
        for(int i = 1; i <= m; i++){
            scanf("%d%d", t + i, s + i);
            for(int j = 1; j <= s[i]; j++){
                scanf("%d", &x);
                g[i].push_back(x);
                h[x].push_back(i);
            }
        }
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(d1, INF, sizeof(d1));
        priority_queue<Node> que;
        d1[1] = 0;
        que.push(Node(1, 0));
        while(!que.empty()){
            Node e = que.top();
            que.pop();
            int u = e.idx;
            if(vis1[u]){
                continue;
            }
            vis1[u] = true;
            for(int i = 0; i < h[u].size(); i++){
                int id = h[u][i];
                if(vis2[id]){
                    continue;
                }
                vis2[id] = true;
                for(int j = 0; j < g[id].size(); j++){
                    int v = g[id][j];
                    if(vis1[v]){
                        continue;
                    }
                    if(d1[v] > d1[u] + t[id]){
                        d1[v] = d1[u] + t[id];
                        que.push(Node(v, d1[v]));
                    }
                }
            }
        }
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(d2, INF, sizeof(d1));
        while(!que.empty()){
            que.empty();
        }
        d2[n] = 0;
        que.push(Node(n, 0));
        while(!que.empty()){
            Node e = que.top();
            que.pop();
            int u = e.idx;
            if(vis1[u]){
                continue;
            }
            vis1[u] = true;
            for(int i = 0; i < h[u].size(); i++){
                int id = h[u][i];
                if(vis2[id]){
                    continue;
                }
                vis2[id] = true;
                for(int j = 0; j < g[id].size(); j++){
                    int v = g[id][j];
                    if(vis1[v]){
                        continue;
                    }
                    if(d2[v] > d2[u] + t[id]){
                        d2[v] = d2[u] + t[id];
                        que.push(Node(v, d2[v]));
                    }
                }
            }
        }
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

