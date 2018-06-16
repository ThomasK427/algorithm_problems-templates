#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int ar[maxn], s[maxn], cnt[maxn];

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", ar + i);
        ar[i] %= K;
    }
    s[0] = 0;
    cnt[0] = 1;
    for(int i = 1; i <= N; i++){
        s[i] = (s[i - 1] + ar[i]) % K;
        cnt[s[i]]++;
    }
    LL ans = 0;
    for(int i = 0; i < K; i++){
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
