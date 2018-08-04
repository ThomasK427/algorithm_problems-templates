#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int ans[maxn];
bool inque[maxn];

struct Node{
    int l, r;
}E[maxn];

bool operator<(const Node& a, const Node& b){
    if(a.l != b.l){
        return a.l < b.l;
    }else{
        return a.r > b.r;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &E[i].l, &E[i].r);
        }
        sort(E, E + m);
        int p = 1, q = 1, cur = E[0].r;
        while(p < m){
            if(E[p].r <= cur){
                p++;
            }else{
                cur = E[p].r;
                E[q++] = E[p++];
            }
        }
        priority_queue<int, vector<int>, greater<int> > que;
        for(int i = 1; i <= n; i++){
            que.push(i);
            inque[i] = true;
        }
        for(int i = 1; i <= n; i++){
            ans[i] = 1;
        }
        p = 1;
        for(int i = 0; i < q; i++){
            while(p < E[i].l){
                if(!inque[ans[p]]){
                    que.push(ans[p]);
                    inque[ans[p]] = true;
                }
                p++;
            }
            int s = (i == 0 ? E[i].l : max(E[i - 1].r + 1, E[i].l)), e = E[i].r;
            for(int j = s; j <= e; j++){
                int u = que.top();
                ans[j] = u;
                inque[u] = false;
                que.pop();
            }
        }
        for(int i = 1; i <= n; i++){
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
