#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    sort(ar, ar + n);
    int ans = INF;
    for(int i = 0; i < n - 1; i++){
        ans = min(ans, abs(ar[i] - ar[i + 1]));
    }
    printf("%d\n", ans);
    return 0;
}
