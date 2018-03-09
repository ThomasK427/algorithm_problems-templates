#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int l, r, a;
    while(~scanf("%d%d%d", &l, &r, &a)){
        if(l > r){
            swap(l, r);
        }
        int ans = l;
        r -= l;
        if(a <= r){
            ans += a;
        }
        else{
            ans += r;
            a -= r;
            ans += a / 2;
        }
        ans *= 2;
        printf("%d\n", ans);
    }
    return 0;
}
