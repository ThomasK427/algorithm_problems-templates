#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 200005;

int n, q;
LL a[maxn], k[maxn], s[maxn];

int main()
{
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    for(int i = 1; i <= q; i++){
        scanf("%lld", k + i);
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    s[n + 1] = inf;
    LL cur = 0;
    for(int i = 1; i <= q; i++){
        cur += k[i];
        int j = lower_bound(s + 1, s + n + 1, cur) - s;
        if(s[j] == cur){
            j++;
        }
        if(j == n + 1){
            cur = 0;
            j = 1;
        }
        printf("%d\n", n - j + 1);
    }
    return 0;
}
