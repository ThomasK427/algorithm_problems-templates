/**
*GCD HDU1695 莫比乌斯反演
*求满足gcd(x, y) = k, 1 <= x <= b, 1 <= y <= d的(x, y)的对数
*即求满足gcd(x / k, y / k) = 1, 1 <= x <= b, 1 <= y <= b的(x, y)的对数
*即求满足gcd(x, y) = 1, 1 <= x <= b / k, 1 <= y <= d / k的(x, y)的对数
*令p = b / k, q = d / k
*令F(n)表示满足n | gcd(x, y), 1 <= x <= p, 1 <= y <= q的(x, y)的对数，F(n) = (p / n)(q / n)
*令f(n)表示满足n = gcd(x, y), 1 <= x <= p, 1 <= y <= q的(x, y)的对数
*由定义F(n) = sigma(f(d)) [n | d]
*由莫比乌斯反演公式得到f(n) = sigma(u(d / n)F(d)) [n | d]
*要求计算的是f(1) = sigma(u(d)F(d)) [1 | d] = sigma(u(d)(p / d)(q / d)) [1 <= d <= min(p, q)]
*令ans(p, q) = f(1), 因为(1, 2), (2, 1)之类的算同一种，需要去重，答案为ans(p, q) - ans(p, p) / 2 (这里设p <= q)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

bool valid[maxn];
int prime[maxn], mob[maxn];
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
}

int main()
{
    getMobius(100000);
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if(k == 0){
            printf("Case %d: 0\n", ++kase);
            continue;
        }
        int p = b / k, q = d / k;
        if(p > q){
            swap(p, q);
        }
        LL ans1 = 0, ans2 = 0;
        for(int i = 1; i <= p; i++){
            ans1 += 1LL * mob[i] * (p / i) * (q / i);
            ans2 += 1LL * mob[i] * (p / i) * (p / i);
        }
        printf("Case %d: %lld\n", ++kase, ans1 - ans2 / 2);
    }
    return 0;
}
