#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

LL h[maxn], sh[maxn];

int main()
{
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", h + i);
    }
    sort(h + 1, h + n + 1);
    sh[0] = 0;
    int c = n + 1;
    for(int i = h[n]; i >= 1; i--){
        while(c > 1 && i <= h[c - 1]){
            c--;
        }
        sh[i] = n + 1 - c;
    }
    for(int i = 1; i <= h[n]; i++){
        sh[i] += sh[i - 1];
    }
    int ans = 0;
    int p = h[n];
    while(p > h[1]){
        p = lower_bound(sh, sh + p + 1, sh[p] - k) - sh;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
