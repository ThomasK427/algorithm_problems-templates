/**
*HDU4983
*n为1时，ans = 1
*n > 1, k > 2时, ans = 0
*n > 1, k = 2时, ans = 1
*n = 1, k = 1时 ans = sigma(count({(a, b) | gcd(a, n) = x, gcd(b, n) = n / x}), n % x == 0)
*1-n中满足gcd(x, n) = k(n % k == 0)的x的个数为phi(n / k)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;

LL phi(LL n){
    LL x = n, ans = n;
    for(LL i = 2; i <= x && i * i <= n; i++){
        if(x % i == 0){
            ans = ans / i * (i - 1);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x > 1){
        ans = ans / x * (x - 1);
    }
    return ans;
}

int main()
{
    LL n, k;
    while(~scanf("%lld%lld", &n, &k)){
        if(n == 1){
            puts("1");
            continue;
        }
        if(k > 2){
            puts("0");
            continue;
        }
        if(k == 2){
            puts("1");
            continue;
        }
        vector<LL> v;
        for(LL i = 1; i * i <= n; i++){
            if(n % i == 0){
                v.push_back(i);
                if(n / i != i){
                    v.push_back(n / i);
                }
            }
        }
        LL ans = 0;
        for(unsigned i = 0; i < v.size(); i++){
            ans = (ans + phi(v[i]) * phi(n / v[i])) % Q;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
