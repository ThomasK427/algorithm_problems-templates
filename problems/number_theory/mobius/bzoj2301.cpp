/**
*bzoj2301 莫比乌斯反演+容斥原理
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

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

LL solve(int p, int q, int k){
    p /= k;
    q /= k;
    if(p > q){
        swap(p, q);
    }
    LL ans = 0;
    for(int L = 1, R = 0; L <= p; L = R + 1){
        R = min(p / (p / L), q / (q / L));
        ans += 1LL * (sum[R] - sum[L - 1]) * (p / L) * (q / L);
    }
    return ans;
}

int main()
{
    getMobius(50005);
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        LL ans = solve(b, d, k) - solve(a - 1, d, k) - solve(c - 1, b, k) + solve(a - 1, c - 1, k);
        printf("%lld\n", ans);
    }
    return 0;
}
