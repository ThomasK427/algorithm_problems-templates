#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const LL Q = 1e9 + 7;
const int maxn = 100005;

vector<int> g[2][maxn];
bool used[maxn];

void bfs(unordered_set<LL>& st, int flag){
    memset(used, 0, sizeof(used));
    queue<int> que;
    que.push(1);
    used[1] = true;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 0; i < g[flag][u].size(); i++){
            if(!used[g[flag][u][i]]){
                if(flag == 0){
                    st.insert(u * Q + g[flag][u][i]);
                }
                else{
                    st.insert(g[flag][u][i] * Q + u);
                }
                que.push(g[flag][u][i]);
                used[g[flag][u][i]] = true;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++){
            g[0][i].clear();
            g[1][i].clear();
        }
        unordered_set<LL> st1, st2, st3;
        for(int i = 0; i < m; i++){
            LL a, b;
            scanf("%lld%lld", &a, &b);
            g[0][a].push_back(b);
            g[1][b].push_back(a);
            st1.insert(a * Q + b);
        }
        bfs(st2, 0);
        bfs(st3, 1);
        int cnt = 0;
        for(auto o : st1){
            if(!st2.count(o) && !st3.count(o)){
                LL a = o / Q, b = o % Q;
                printf("%lld %lld\n", a, b);
                cnt++;
                if(cnt == m - 2 * n){
                    break;
                }
            }
        }
    }
    return 0;
}

