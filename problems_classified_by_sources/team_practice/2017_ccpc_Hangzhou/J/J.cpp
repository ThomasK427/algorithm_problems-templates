#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const LL Q = 998244353;
const int maxn = 100005;

int val[2][maxn * 4], lazy[2][maxn * 4];

void push_up(int id, int o){
    val[id][o] = min(val[id][o * 2], val[id][o * 2 + 1]);
}

void push_down(int id, int o){
    if(lazy[id][o]){
        lazy[id][o * 2] += lazy[id][o];
        lazy[id][o * 2 + 1] += lazy[id][o];
        val[id][o * 2] += lazy[id][o];
        val[id][o * 2 + 1] += lazy[id][o];
        lazy[id][o] = 0;
    }
}

int query(int id, int o, int l, int r, int a, int b){
    if(a <= l && r <= b){
        return val[id][o];
    }
    else if(a > r || b < l){
        return INF;
    }
    else{
        push_down(id, o);
        int mid = (l + r) / 2, res = INF;
        res = min(res, query(id, o * 2, l, mid, a, b));
        res = min(res, query(id, o * 2 + 1, mid + 1, r, a, b));
        return res;
    }
}

void add(int id, int o, int l, int r, int a, int b, int x){
    if(a <= l && r <= b){
        val[id][o] += x;
        lazy[id][o] += x;
    }
    else if(a > r || b < l){
        return;
    }
    else{
        push_down(id, o);
        int mid = (l + r) / 2;
        add(id, o * 2, l, mid, a, b, x);
        add(id, o * 2 + 1, mid + 1, r, a, b, x);
        push_up(id, o);
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int N, m;
        scanf("%d%d", &N, &m);
        int n = 1;
        while(n < N){
            n *= 2;
        }
        memset(val, 0, sizeof(val));
        memset(lazy, 0, sizeof(lazy));
        while(m--){
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            int id = (x == 3);
            add(id, 1, 1, n, a, b, 1);
        }
        int c1 = query(0, 1, 1, n, 1, N), c2 = query(1, 1, 1, n, 1, N);
        LL ans = 1;
        for(int i = 0; i < c1; i++){
            ans = ans * 2 % Q;
        }
        for(int i = 0; i < c2; i++){
            ans = ans * 3 % Q;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
