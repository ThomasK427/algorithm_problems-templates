#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int n, x, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        ans += abs(x);
    }
    printf("%d\n", ans);
    return 0;
}
