#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int ans[maxn];

struct Node{
    int l, r;
};

bool operator<(const Node& a, const Node& b){
    if(a.l != b.l){
        return a.l < b.l;
    }else{
        return a.r > b.r;
    }
}

Node E[maxn];

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
        sort(E, E + n);
        int p = 1, q = 1, cur = E[0].r;
        while(p < m){
            if(E[p].r <= cur){
                p++;
            }else{
                E[q++] = E[p];
                cur = E[p++].r;
            }
        }
        m = q;
        p = 0;
        int low = INF, high = INF;
        for(int i = 1; i <= n; i++){
            if(p >= m){
                ans[i] = 1;
            }else if(i < E[p].l){
                ans[i] = 1;
            }else if(i == E[p].l){
                ans[i] = 1;
            }else if(i < E[p].r){
                ans[i] = ans[i - 1] + 1;
            }else if(i == E[p].r){

            }
        }
    }
    return 0;
}
