#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
const LL Q = 1e9 + 7;

LL f[maxn];

int main()
{
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i < maxn; i++){
        f[i] = (f[i - 1] + f[i - 2]) % Q;
    }
    int N;
    scanf("%d", &N);
    printf("%lld\n", f[N]);
    return 0;
}
