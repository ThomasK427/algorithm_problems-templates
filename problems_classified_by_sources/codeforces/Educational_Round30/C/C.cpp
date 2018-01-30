#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    int n, k, x, ans = 0;
    scanf("%d%d%d", &n, &k, &x);
    for(int i = 1; i <= n; i++){
        int y;
        scanf("%d", &y);
        if(i < n - k + 1){
            ans += y;
        }
        else{
            ans += min(x, y);
        }
    }
    printf("%d\n", ans);
    return 0;
}

