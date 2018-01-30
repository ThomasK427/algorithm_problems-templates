#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10005;

LL ar[maxn];

inline LL Abs(LL x)
{
    return x > 0 ? x : -x;
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", ar + i);
    }
    sort(ar + 1, ar + N + 1);
    int p = (N + 1) / 2;
    LL ans = 0;
    for(int i = 1; i <= N; i++){
        ans += Abs(ar[i] - ar[p]);
    }
    printf("%lld\n", ans);
    return 0;
}
