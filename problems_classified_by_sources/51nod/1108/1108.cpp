#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10005;

LL ar[maxn], br[maxn], cr[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld%lld", ar + i, br + i, cr + i);
    }
    sort(ar, ar + N);
    sort(br, br + N);
    sort(cr, cr + N);
    LL ans = 0;
    for(int i = 0; i < N; i++){
        ans += abs(ar[i] - ar[N / 2]);
    }
    for(int i = 0; i < N; i++){
        ans += abs(br[i] - br[N / 2]);
    }
    for(int i = 0; i < N; i++){
        ans += abs(cr[i] - cr[N / 2]);
    }
    printf("%lld\n", ans);
    return 0;
}
