#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

LL x[maxn], d[maxn], gl[maxn], gr[maxn];

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", x + i);
    }
    if(n <= 3){
        puts("0");
        return 0;
    }
    sort(x + 1, x + n + 1);
    for(int i = 1; i < n; i++){
        d[i] = x[i + 1] - x[i];
    }
    gl[0] = 0;
    gl[1] = d[1];
    for(int i = 2; i < n; i++){
        gl[i] = gcd(gl[i - 1], d[i]);
    }
    gr[n] = 0;
    gr[n - 1] = d[n - 1];
    for(int i = n - 2; i >= 1; i--){
        gr[i] = gcd(gr[i + 1], d[i]);
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i < n; i++){
        LL g = gcd(gl[i - 1], gr[i + 1]);
        ans = min(ans, (x[i] - x[1]) / g + (x[n] - x[i + 1]) / g + 2 - n);
    }
    printf("%lld\n", ans);
    return 0;
}
