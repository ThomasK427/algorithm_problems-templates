#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int ar[maxn];
int sumv[maxn * 4];
int n;

void push_up(int o){
    sumv[o] = sumv[o * 2] + sumv[o * 2 + 1];
}

void build_tree(int o, int l, int r){
    if(l == r){
        sumv[o] = ar[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(o * 2, l, mid);
    build_tree(o * 2 + 1, mid + 1, r);
    push_up(o);
}

void add(int o, int l, int r, int id, int x){
    if(id < l || id > r){
        return;
    }
    if(l == r){
        sumv[o] += x;
        return;
    }
    int mid = (l + r) / 2;
    add(o * 2, l, mid, id, x);
    add(o * 2 + 1, mid + 1, r, id, x);
    push_up(o);
}

int query(int o, int l, int r, int a, int b){
    if(b < l || a > r){
        return 0;
    }
    if(a <= l && r <= b){
        return sumv[o];
    }
    int mid = (l + r) / 2;
    int res = 0;
    res += query(o * 2, l, mid, a, b);
    res += query(o * 2 + 1, mid + 1, r, a, b);
    return res;
}

int main()
{
    int T, kase = 0;;
    scanf("%d", &T);
    while(T--){
        printf("Case %d:\n", ++kase);
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        int n = 1;
        while(n < N){
            n *= 2;
        }
        memset(sumv, 0, sizeof(sumv));
        build_tree(1, 1, n);
        char str[10];
        int i, j;
        while(~scanf("%s", str)){
            if(strcmp(str, "Add") == 0){
                scanf("%d%d", &i, &j);
                add(1, 1, n, i, j);
            }
            else if(strcmp(str, "Sub") == 0){
                scanf("%d%d", &i, &j);
                add(1, 1, n, i, -j);
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

