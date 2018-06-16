#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int ar[maxn], val[maxn * 4 + 10], lazy[maxn * 4 + 10];

void push_up(int o){
    val[o] = min(val[o * 2], val[o * 2 + 1]);
}

void push_down(int o){
    if(lazy[o]){
        lazy[o * 2] += lazy[o];
        lazy[o * 2 + 1] += lazy[o];
        val[o * 2] += lazy[o];
        val[o * 2 + 1] += lazy[o];
        lazy[o] = 0;
    }
}

void build_tree(int o, int l, int r){
    if(l == r){
        val[o] = ar[l];
    }
    else{
        int mid = (l + r) / 2;
        build_tree(o * 2, l, mid);
        build_tree(o * 2 + 1, mid + 1, r);
        push_up(o);
    }
}

int query(int o, int l, int r, int a, int b){
    if(a <= l && r <= b){
        return val[o];
    }
    else if(a > r || b < l){
        return INF;
    }
    else{
        push_down(o);
        int mid = (l + r) / 2, res = INF;
        res = min(res, query(o * 2, l, mid, a, b));
        res = min(res, query(o * 2 + 1, mid + 1, r, a, b));
        return res;
    }
}

void add(int o, int l, int r, int a, int b, int x){
    if(a <= l && r <= b){
        val[o] += x;
        lazy[o] += x;
    }
    else if(a > r || b < l){
        return;
    }
    else{
        push_down(o);
        int mid = (l + r) / 2;
        add(o * 2, l, mid, a, b, x);
        add(o * 2 + 1, mid + 1, r, a, b, x);
        push_up(o);
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        memset(ar, INF, sizeof(ar));
        memset(val, INF, sizeof(val));
        memset(lazy, 0, sizeof(lazy));
        int N, K;
        scanf("%d%d", &N, &K);
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        int n = 1;
        while(n < N){
            n *= 2;
        }
        build_tree(1, 1, n);
        int ans = 0;
        for(int i = 1; i <= N - K + 1; i++){
            int t = query(1, 1, n, i, i + K - 1);
            ans += t;
            add(1, 1, n, i, i + K - 1, -t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
