#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10005;

LL x[maxn], s1[maxn], s2[maxn];

int main()
{
    int M, N;
    scanf("%d%d", &M, &N);
    for(int i = 1; i <= M; i++){
        scanf("%lld", x + i);
    }
    sort(x + 1, x + M + 1);
    s1[0] = 0;
    s2[0] = 0;
    for(int i = 1; i <= M; i++){
        s1[i] = s1[i - 1] + x[i];
        s2[i] = s2[i - 1] + x[i] * x[i];
    }
    LL ans = inf;
    for(int i = 1; i <= M - N + 1; i++){
        double res = (s2[i + N - 1] - s2[i - 1]) - (s1[i + N - 1] - s1[i - 1]) / double(N) * (s1[i + N - 1] - s1[i - 1]);
        ans = min(ans, LL(res));
    }
    printf("%lld\n", ans);
    return 0;
}
