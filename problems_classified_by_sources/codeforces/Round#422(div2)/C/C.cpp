#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn = 200100;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Node{
    LL a, b, cost, tp;
    friend bool operator<(const Node& n1, const Node& n2){
        if(n1.a != n2.a){
            return n1.a < n2.a;
        }
        else{
            return n1.tp < n2.tp;
        }
    }
}E[maxn * 2];

LL mp[maxn];

int main()
{
    LL n, x;
    scanf("%lld%lld", &n, &x);
    LL l, r, c, cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &l, &r, &c);
        E[cnt].a = l;
        E[cnt].b = r;
        E[cnt].cost = c;
        E[cnt++].tp = 0;
        E[cnt].a = r;
        E[cnt].b = l;
        E[cnt].cost = c;
        E[cnt++].tp = 1;
    }
    sort(E, E + cnt);
    for(LL i = 0; i <= 200050; i++){
        mp[i] = INF;
    }
    LL ans = INF;
    for(LL i = 0; i < cnt; i++){
        if(E[i].tp == 0){
            LL len = E[i].b - E[i].a + 1;
            if(x > len){
                ans = min(ans, E[i].cost + mp[x - len]);
            }
        }
        else{
            LL len = E[i].a - E[i].b + 1;
            mp[len] = min(mp[len], E[i].cost);
        }
    }
    if(ans >= INF){
        puts("-1");
    }
    else{
        printf("%d\n", ans);
    }
    return 0;
}
