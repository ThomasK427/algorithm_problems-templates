#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200005;

int ar[maxn], val[maxn * 4];

void push_up(int o){
    val[o] = max(val[o * 2], val[o * 2 + 1]);
}

void build_tree(int o, int l, int r, int a, int b){
    if(a > r || b < l){
        return;
    }
    else if(l == r){
        val[o] = ar[l];
    }
    else{
        int mid = (l + r) / 2;
        build_tree(o * 2, l, mid, a, b);
        build_tree(o * 2 + 1, mid + 1, r, a, b);
        push_up(o);
    }
}

int query(int o, int l, int r, int a, int b){
    if(a > r || b < l){
        return 0;
    }
    else if(a <= l && r <= b){
        return val[o];
    }
    else{
        int mid = (l + r) / 2, res = 0;
        res = max(res, query(o * 2, l, mid, a, b));
        res = max(res, query(o * 2 + 1, mid + 1, r, a, b));
        return res;
    }
}

void update(int o, int l, int r, int id, int x){
    if(id < l || id > r){
        return;
    }
    else if(l == r){
        val[o] = x;
    }
    else{
        int mid = (l + r) / 2;
        update(o * 2, l, mid, id, x);
        update(o * 2 + 1, mid + 1, r, id, x);
        push_up(o);
    }
}

int main()
{
    int N, M;
    while(~scanf("%d%d", &N, &M)){
        memset(ar, 0, sizeof(ar));
        memset(val, 0, sizeof(val));
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        int n = 1;
        while(n < N){
            n *= 2;
        }
        build_tree(1, 1, n, 1, N);
        while(M--){
            char c;
            int a, b;
            getchar();
            scanf("%c%d%d", &c, &a, &b);
            if(c == 'Q'){
                printf("%d\n", query(1, 1, n, a, b));
            }
            else{
                update(1, 1, n, a, b);
            }
        }
    }
    return 0;
}
