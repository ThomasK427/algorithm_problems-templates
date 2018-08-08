#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
const int maxq = 205;
const double eps = 1e-5;

int x[maxq], y[maxq], r[maxq];

struct segment{
    int l, r;
}seg[maxq];

bool operator<(const segment& a, const segment& b){
    if(a.l != b.l){
        return a.l < b.l;
    }else{
        return a.r < b.r;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M, q;
        scanf("%d%d%d", &N, &M, &q);
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", x + i, y + i, r + i);
        }
        int ans = M * N;
        for(int i = 0; i < N; i++){
            int p = 0;
            for(int j = 0; j < q; j++){
                int dx = abs(x[j] - i);
                if(dx > r[j]){
                    continue;
                }
                int L = int(ceil(y[j] - sqrt(r[j] * r[j] - dx * dx)) + eps);
                int R = int(floor(y[j] + sqrt(r[j] * r[j] - dx * dx)) + eps);
                seg[p].l = max(0, L);
                seg[p++].r = min(M - 1, R);
            }
            sort(seg, seg + p);
            int t = 0, cur = 0;
            for(int j = 0; j < p; j++){
                if(cur > seg[j].r){
                    continue;
                }else{
                    t += seg[j].r - max(cur, seg[j].l) + 1;
                    cur = seg[j].r + 1;
                }
            }
            ans -= t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
