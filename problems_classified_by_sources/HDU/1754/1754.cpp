#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 200005;

int ar[maxn], maxv[maxn * 4], n;

void push_up(int o){
    maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
}

void build_tree(int o, int l, int r){
    if(l == r){
        maxv[o] = ar[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(o * 2, l, mid);
    build_tree(o * 2 + 1, mid + 1, r);
    push_up(o);
}

void setx(int id, int x){
    int o = id + n - 1;
    maxv[o] = x;
    do{
        o /= 2;
        push_up(o);
    }while(o > 1);
}

int query(int o, int l, int r, int a, int b){
    if(b < l || a > r){
        return -INF;
    }
    if(a <= l && r <= b){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    int res1 = query(o * 2, l, mid, a, b);
    int res2 = query(o * 2 + 1, mid + 1, r, a, b);
    return max(res1, res2);
}

int main()
{
    int N, M;
    while(~scanf("%d%d", &N, &M)){
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        n = 1;
        while(n < N){
            n *= 2;
        }
        for(int i = N + 1; i <= n; i++){
            ar[i] = -INF;
        }
        build_tree(1, 1, n);
        while(M--){
            char c;
            int a, b;
            getchar();
            scanf("%c%d%d", &c, &a, &b);
            if(c == 'Q'){
                printf("%d\n", query(1, 1, n, a, b));
            }
            else{
                setx(a, b);
            }
        }
    }
    return 0;
}
