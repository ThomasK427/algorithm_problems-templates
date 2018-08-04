#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int w[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", w + i);
        }
        int ans = int(sqrt(abs(w[1] - w[n])));
        printf("%d\n", ans);
    }
    return 0;
}
