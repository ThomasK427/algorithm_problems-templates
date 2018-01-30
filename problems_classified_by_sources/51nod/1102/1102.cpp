#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

LL a[maxn];
int n;

int Len(int idx)
{
    int cnt = 1;
    for(int i = idx + 1; i <= n; i++){
        if(a[i] >= a[idx])cnt++;
        else break;
    }
    for(int i = idx - 1; i >= 1; i--){
        if(a[i] >= a[idx])cnt++;
        else break;
    }
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, a[i] * Len(i));
    }
    printf("%lld\n", ans);
    return 0;
}
