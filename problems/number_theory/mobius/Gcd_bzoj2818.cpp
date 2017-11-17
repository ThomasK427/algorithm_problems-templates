/**
*Gcd bzoj2818
*同bzoj1101、洛谷P3455
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10000005;

bool valid[maxn];
int prime[maxn], mob[maxn], sum[maxn];
int tot;

void getMobius(int n){
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    mob[1] = 1;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            mob[i] = -1;
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j]){
                mob[i * prime[j]] = -mob[i];
            }
            else{
                mob[i * prime[j]] = 0;
                break;
            }
        }
    }
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + mob[i];
    }
}

int main()
{
    getMobius(10000000);
    int n;
    scanf("%d", &n);
    LL ans = 0;
    for(int i = 1; i <= tot && prime[i] <= n; i++){
        int p = n / prime[i];
        for(int L = 1, R = 0; L <= p; L = R + 1){
            R = p / (p / L);
            ans += 1LL * (sum[R] - sum[L - 1]) * (p / L) * (p / L);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
