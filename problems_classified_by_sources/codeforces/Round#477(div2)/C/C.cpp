#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int l[maxn], e[maxn], rl[maxn], re[maxn];

int main()
{
    int n, m, cl, ce, v;
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    for(int i = 0; i < cl; i++){
        scanf("%d", l + i);
    }
    l[cl] = INF;
    for(int i = 0; i < cl; i++){
        rl[i] = l[cl - 1 - i];
    }
    rl[cl] = 0;
    for(int i = 0; i < ce; i++){
        scanf("%d", e + i);
    }
    e[ce] = INF;
    for(int i = 0; i < ce; i++){
        re[i] = e[ce - 1 - i];
    }
    re[ce] = 0;
    int q;
    scanf("%d", &q);
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(y1 > y2){
            swap(y1, y2);
        }
        int ans = INF;
        if(x1 == x2){
            ans = y2 - y1;
        }
        else{
            if(cl > 0){
                int p = lower_bound(l, l + cl, y1) - l, q = lower_bound(rl, rl + cl, y2, greater<int>()) - rl;
                int tmp = abs(x1 - x2) + y2 - y1;
                int d = min(max(0, l[p] - y2), max(0, y1 - rl[q]));
                tmp += 2 * d;
                ans = min(ans, tmp);
            }
            if(ce > 0){
                int p = lower_bound(e, e + ce, y1) - e, q = lower_bound(re, re + ce, y2, greater<int>()) - re;
                int tmp = (abs(x1 - x2) + v - 1) / v + y2 - y1;
                int d = min(max(0, e[p] - y2), max(0, y1 - re[q]));
                tmp += 2 * d;
                ans = min(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

