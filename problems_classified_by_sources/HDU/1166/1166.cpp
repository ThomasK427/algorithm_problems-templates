#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int ar[maxn];
int val[maxn * 4];

void push_up(int o){
    val[o] = val[o * 2] + val[o * 2 + 1];
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
        res += query(o * 2, l, mid, a, b);
        res += query(o * 2 + 1, mid + 1, r, a, b);
        return res;
    }
}

void update(int o, int l, int r, int id, int x){
    if(id < l || id > r){
        return;
    }
    else if(l == r){
        val[o] += x;
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
    int T, kase = 0;;
    scanf("%d", &T);
    while(T--){
        printf("Case %d:\n", ++kase);
        memset(ar, 0, sizeof(ar));
        memset(val, 0, sizeof(val));
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        int n = 1;
        while(n < N){
            n *= 2;
        }
        build_tree(1, 1, n, 1, N);
        char str[10];
        int i, j;
        while(~scanf("%s", str)){
            if(strcmp(str, "Add") == 0){
                scanf("%d%d", &i, &j);
                update(1, 1, n, i, j);
            }
            else if(strcmp(str, "Sub") == 0){
                scanf("%d%d", &i, &j);
                update(1, 1, n, i, -j);
            }
            else if(strcmp(str, "Query") == 0){
                scanf("%d%d", &i, &j);
                printf("%d\n", query(1, 1, n, i, j));
            }
            else{
                break;
            }
        }
    }
    return 0;
}
