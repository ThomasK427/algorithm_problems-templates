#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int n, N;
int ar[maxn], sumv[maxn * 4], mark[maxn * 4];

void push_up(int o){
    sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}

void push_down(int o, int l, int r){
    if(mark[o] == 0){
        return;
    }
    mark[o * 2] = mark[o];
    mark[o * 2 + 1] = mark[o];
    int mid = (l + r) / 2;
    sumv[o * 2] = (mid - l + 1) * mark[o];
    sumv[o * 2 + 1] = (r - mid) * mark[o];
    mark[o] = 0;
}

void build_tree(int o, int l, int r){
    if(l > N){
        return;
    }
    if(l == r){
        sumv[o] = ar[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(o * 2, l, mid);
    build_tree(o * 2 + 1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int a, int b, int x){
    if(a > r || b < l){
        return;
    }
    if(a <= l && r <= b){
        sumv[o] = (r - l + 1) * x;
        mark[o] = x;
        return;
    }
    push_down(o, l, r);
    int mid = (l + r) / 2;
    update(o * 2, l, mid, a, b, x);
    update(o * 2 + 1, mid + 1, r, a, b, x);
    push_up(o);
}

int query(int o, int l, int r, int a, int b){
    if(a > r || b < l){
        return 0;
    }
    if(a <= l && r <= b){
        return sumv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) / 2, res = 0;
    res += query(o * 2, l, mid, a, b);
    res += query(o * 2 + 1, mid + 1, r, a, b);
    return res;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++){
        scanf("%d", &N);
        memset(ar, 0, sizeof(ar));
        for(int i = 1; i <= N; i++){
            ar[i] = 1;
        }
        n = 1;
        while(n < N){
            n *= 2;
        }
        memset(mark, 0, sizeof(mark));
        build_tree(1, 1, n);
        int Q;
        scanf("%d", &Q);
        while(Q--){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            update(1, 1, n, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase, query(1, 1, n, 1, N));
    }
    return 0;
}
