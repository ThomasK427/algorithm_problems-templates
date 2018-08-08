#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

char A[maxn];
int ar[maxn * 4];
int sum[26][maxn];

int minv[maxn * 4];
int n;

void push_up(int o){
    minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
}

void build_tree(int o, int l, int r){
    if(l == r){
        minv[o] = ar[l];
    }else{
        int mid = (l + r) / 2;
        build_tree(o * 2, l, mid);
        build_tree(o * 2 + 1, mid + 1, r);
        push_up(o);
    }
}

int query(int o, int l, int r, int a, int b){
    if(a <= l && r <= b){
        return minv[o];
    }else if(a > r || b < l){
        return INF;
    }else{
        int mid = (l + r) / 2;
        int res = INF;
        res = min(res, query(o * 2, l, mid, a, b));
        res = min(res, query(o * 2 + 1, mid + 1, r, a, b));
        return res;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++){
        printf("Case #%d:\n", kase);
        int N, q;
        scanf("%d%d", &N, &q);
        scanf("%s", A + 1);
        memset(ar, INF, sizeof(ar));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= N; i++){
            int p = A[i] - 'A';
            ar[i] = p;
            for(int j = 0; j < 26; j++){
                sum[j][i] = sum[j][i - 1];
            }
            sum[p][i]++;
        }
        n = 1;
        while(n < N){
            n *= 2;
        }
        build_tree(1, 1, n);
        while(q--){
            int l, r;
            scanf("%d%d", &l, &r);
            int p = query(1, 1, n, l, r);
            printf("%d\n", sum[p][r] - sum[p][l - 1]);
        }
    }
    return 0;
}
