#include <bits/stdc++.h>
using namespace std;
const int maxn = 16777216 + 10;

int val[maxn * 2];
int vis[10005];

void push_down(int o, int l, int r){
    val[o * 2] = val[o];
    val[o * 2 + 1] = val[o];
}

int query(int o, int l, int r, int id){
    if(id > r || id < l){
        return 0;
    }
    else if(l == r){
        return val[o];
    }
    else{
        int mid = (l + r) / 2, res = 0;
        res = max(res, query(o * 2, l, mid, id));
        res = max(res, query(o * 2 + 1, mid + 1, r, id));
        return res;
    }
}

void update(int o, int l, int r, int a, int b, int x){
    if(a > r || b < l){
        return;
    }
    else if(a <= l && r <= b){
        val[o] = x;
    }
    else{
        int mid = (l + r) / 2;
        update(o * 2, l, mid, a, b, x);
        update(o * 2 + 1, mid + 1, r, a, b, x);
    }
}

int main()
{
    int N = 10000000, n = 16777216;
    int T;
    scanf("%d", &T);
    while(T--){
        memset(val, 0, sizeof(val));
        int K;
        scanf("%d", &K);
        for(int i = 1; i <= K; i++){
            int l, r;
            scanf("%d%d", &l, &r);
            update(1, 1, n, l, r, i);
        }
        for(int i = 1; i <= N; i++){
            int t = query()
        }
    }
    return 0;
}
