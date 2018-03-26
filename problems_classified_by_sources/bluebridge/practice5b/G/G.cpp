#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int x[maxn], d[maxn], pre[maxn], nxt[maxn];
bool used[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", x + i);
    }
    priority_queue<int, vector<int>, greater<int> > que;
    int head = 1, tail = n;
    for(int i = 1; i < n; i++){
        d[i] = x[i] - x[i + 1];
        if(abs(d[i]) == 1){
            que.push(i);
        }
    }
    for(int i = 1; i <= n; i++){
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    pre[1] = -1;
    nxt[n] = -1;
    head = 1;
    tail = n;
    memset(used, 0, sizeof(used));
    int ans = 0;
    while(!que.empty()){
        int u = que.top(), v = nxt[u];
        que.pop();
        if(abs(d[u]) != 1 || used[u]){
            continue;
        }
        ans++;
        if(x[u] < x[v]){
            used[v] = true;
            int w = nxt[v];
            if(w == -1){
                nxt[u] = -1;
            }
            else{
                pre[w] = u;
                nxt[u] = w;
                d[u] = x[u] - x[w];
                if(abs(d[u]) == 1){
                    que.push(u);
                }
            }
        }
        else{
            used[u] = true;
            int w = pre[u];
            if(w == -1){
                pre[v] = -1;
            }
            else{
                nxt[w] = v;
                pre[v] = w;
                d[w] = x[w] - x[v];
                if(abs(d[w]) == 1){
                    que.push(w);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
