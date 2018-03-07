#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 505;

struct Node{
    int idx, dx;
    bool isleft;
    Node(){}
    Node(int idx, int dx, bool isleft){
        this->idx = idx;
        this->dx = dx;
        this->isleft = isleft;
    }
    friend bool operator<(const Node& e1, const Node& e2){
        return e1.dx < e2.dx;
    }
};

char s[maxn];
int g[maxn][maxn];
int t[maxn], l[maxn], r[maxn];

int count(int i){
    return r[i] - l[i] + 1;
}

int main()
{
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    priority_queue<Node> que;
    memset(t, 0, sizeof(t));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '1'){
                g[i][++t[i]] = j;
            }
        }
        l[i] = 1;
        r[i] = t[i];
        if(t[i] == 0){
            continue;
        }
        else{
            ans += g[i][t[i]] - g[i][1] + 1;
            if(t[i] == 1){
                que.push(Node(i, 1, true));
            }
            else if(t[i] == 2){
                que.push(Node(i, g[i][t[i]] - g[i][1], true));
            }
            else{
                que.push(Node(i, g[i][2] - g[i][1], true));
                que.push(Node(i, g[i][t[i]] - g[i][t[i] - 1], false));
            }
        }
    }
    while(k--){
        if(que.empty()){
            break;
        }
        Node u = que.top();
        que.pop();
        int idx = u.idx, dx = u.dx;
        ans -= dx;
        if(count(idx) == 1){
            continue;
        }
        else if(count(idx) == 2){
            que.push(Node(idx, 1, true));
        }
        else{
            if(u.isleft){
                l[idx]++;
                que.push(Node(idx, g[idx][l[idx] + 1] - g[idx][l[idx]], true));
            }
            else{
                r[idx]--;
                que.push(Node(idx, g[idx][r[idx]] - g[idx][r[idx] - 1], false));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
