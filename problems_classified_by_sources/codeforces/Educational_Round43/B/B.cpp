#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int main()
{
    LL n, m, k, x, y;
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k <= n - 1){
        y = k + 1;
        x = 1;
    }
    else if(k <= n + m - 2){
        y = n;
        x = k - n + 2;
    }
    else{
        LL a = k - (n + m - 2), c = m - 1;
        LL b = a / (2 * c) * 2;
        x = m;
        y = n - b;
        a %= (2 * c);
        if(a >= 1 && a <= c){
            x = m - a + 1;
            y--;
        }
        else if(a > c){
            a -= c;
            x = a + 1;
            y -= 2;
        }
    }
    printf("%lld %lld\n", y, x);
    return 0;
}
