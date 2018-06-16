#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 200005;

int a[maxn], b[maxn];

int main()
{
    int T, N, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &K);
        for(int i = 0; i < N; i++){
            scanf("%d", a + i);
        }
        for(int i = 0; i < N; i++){
            scanf("%d", b + i);
        }
        sort(a, a + N);
        sort(b, b + N);
        LL ans = 0;
        for(int i = 0; i < N; i++){
            int p = lower_bound(b, b + N, K - a[i]) - b;
            ans += N - p;
        }
        ans /= 2;
        printf("%lld\n", ans);
    }
    return 0;
}
