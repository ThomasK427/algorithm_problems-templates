#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e6 + 6;
const LL Mod = 1e9 + 7;

LL quickpow(LL a, LL b, LL Mod)
{
    LL ret = 1;
    a %= Mod;//至关重要！！！
    while(b)
    {
        if(b & 1)   ret = ret * a % Mod;
        b >>= 1;
        a = (a * a) % Mod;
    }
    return ret;
}

LL f[maxn];

LL fac[maxn], invf[maxn];
void init()
{
    int limit = 2000000;
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)   fac[i] = i * fac[i - 1] % Mod;
    invf[limit] = quickpow(fac[limit], Mod - 2, Mod);
    for(int i = limit - 1; i >= 0; i --) invf[i] = invf[i + 1] * (i + 1) % Mod;
}
long long C(int n, int m)
{
    return fac[n] * invf[m] % Mod * invf[n-m] % Mod;
}


int main()
{
    init();
    f[0] = 0, f[1] = 1;
    for(int i = 2; i <= 2000000; i++)
        f[i] = (f[i-1] + f[i-2]) % (Mod - 1);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        long long q = C(n + k - 1, k - 1), p = q;
        for(int i = 1; i <= k && i <= n; i++)
        {
            if(n % i == 0)
            {
                int cnt = n / i;
                long long t = (quickpow(2, f[cnt], Mod) - 2 + Mod) % Mod * C(k, i) % Mod;
                p = (p + t) % Mod;
            }

        }
        long long inv = quickpow(q, Mod-2, Mod);
        printf("%lld\n", p*inv%Mod);
    }
    return 0;
}
