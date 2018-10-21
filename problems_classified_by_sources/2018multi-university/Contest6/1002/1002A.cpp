#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 1000005;

int cnt[maxn];
int n, k;
LL fac[maxn], fib[maxn], buf[maxn];

LL type = 0, ans = 0;

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

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int t, int d){
    if(d == k){
        cnt[d] = t;
        type++;
        LL tmp = fac[n];
        for(int i = 1; i <= k; i++){
            tmp = tmp * inv(fac[cnt[i]]) % Q;
        }
        solution += tmp;
        LL score = 0;
        for(int i = 1; i <= k; i++){
            buf[i] = qpow(2, fib[cnt[i]]) - 1;
            score = gcd(score, buf[i]);
        }
        ans = (ans + score ) % Q;
    }else{
        for(int i = 0; i <= t; i++){
            cnt[d] = i;
            dfs(t - i, d + 1);
        }
    }
}

int main()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % Q;
    }
    fac[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fac[i] = fac[i - 1] * i % Q;
    }
    n = 6;
    k = 8;
    dfs(n, 1);
    LL p = ans, q = qpow(k, n);
    cout << p * inv(type) % Q << endl;
    return 0;
}
