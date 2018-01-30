#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const long long maxn = 2005;

LL ar[maxn];

int main()
{
    LL n, k;
    while(~scanf("%lld%lld", &n, &k)){
        for(LL i = 0; i < n; i++){
            scanf("%lld", ar + i);
        }
        sort(ar, ar + n);
        k *= 2;
        LL ans = 0;
        for(LL i = 0; i < n; i++){
            if(k >= ar[i]){
                k = max(k, 2 * ar[i]);
            }
            else{
                while(k < ar[i]){
                    ans++;
                    k *= 2;
                }
                k = max(k, 2 * ar[i]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
