#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int n = abs(a - b), m = n / 2, ans = m * (m + 1);
    if(n % 2 == 1){
        ans += m + 1;
    }
    printf("%d\n", ans);
    return 0;
}
