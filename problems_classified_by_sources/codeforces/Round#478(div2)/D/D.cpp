#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 200005;
const LL base = 1e9;
const LL Q = 2e9 + 1;

int main()
{
    int n;
    LL a, b;
    scanf("%d%lld%lld", &n, &a, &b);
    map<LL, LL> mp1, mp2;
    for(int i = 0; i < n; i++){
        LL x, vx, vy;
        scanf("%lld%lld%lld", &x, &vx, &vy);
        mp1[vy - a * vx]++;
        mp2[(vx + base) * Q + (vy + base)]++;
    }
    LL res = 0;
    for(auto o : mp1){
        res += o.second * (o.second - 1);
    }
    for(auto o : mp2){
        res -= o.second * (o.second - 1);
    }
    printf("%lld\n", res);
    return 0;
}
