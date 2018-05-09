#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL Q = 1e9 + 9;
const int maxn = 100005;
char str[maxn];

LL qpow(LL a, LL n){
    LL base = a % Q, res = 1;
    while(n){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

LL inv(LL x){
    return qpow(x, Q - 2);
}

int main()
{
    LL n, a, b, k;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    scanf("%s", str);
    LL m = (n + 1) / k;
    if(a == b){
        LL sum = 0, base = qpow(a, n);
        for(LL i = 0; i < k; i++){
            if(str[i] == '+'){
                sum++;
            }
            else{
                sum--;
            }
        }
        sum = (sum + Q) % Q;
        LL ans = sum * base % Q * m % Q;
        printf("%lld\n", ans);
        return 0;
    }
    LL q = qpow(b * inv(a) % Q ,k);
    LL p = ((qpow(q, m) - 1 + Q) % Q) * inv((q - 1 + Q) % Q) % Q;
    LL ans = 0;
    for(LL i = 0; i < k; i++){
        LL s = (str[i] == '+' ? 1LL : Q - 1LL);
        s = s * qpow(a, n - i) % Q * qpow(b, i) % Q;
        ans = (ans + s) % Q;
    }
    ans = ans * p % Q;
    printf("%lld\n", ans);
    return 0;
}
