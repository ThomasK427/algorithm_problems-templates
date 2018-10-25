#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

int a[maxn], b[maxn], p[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", b + i);
    }
    int cur = 0;
    for(int i = 1; i <= n; i++){
        int ans = max(0, p[b[i]] - cur);
        cur = max(cur, p[b[i]]);
        printf("%d%c", ans, i == n ? '\n' : ' ');
    }
    return 0;
}
