#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1000000007;
const int maxn = 40005;

LL fac[maxn];
LL inv[maxn];
int s[maxn];
int par[maxn];

LL extgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        LL r = extgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

void CreateTable()
{
    fac[0] = 1;
    for(int i = 1; i <= 40000; i++){
        fac[i] = fac[i - 1] * i % Q;
    }
    for(int i = 1; i <= 40000; i++){
        LL x, y;
        LL d = extgcd(i, Q, x, y);
        inv[i] = (x + Q) % Q;
    }
}

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    CreateTable();
    int T;
    T = read();
    while(T--){
        int n, m;
        n = read();
        m = read();
        for(int i = 1; i <= n; i++){
            s[i] = 1;
        }
        memset(par, -1, sizeof(par));
        int a, b;
        while(m--){
            a = read();
            b = read();
            par[a] = b;
        }
        for(int i = 1; i <= n; i++){
            int x = i;
            while(par[x] > 0){
                x = par[x];
                s[x]++;
            }
        }
        LL ans = fac[n];
        for(int i = 1; i <= n; i++){
            ans = ans * inv[s[i]] % Q;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
