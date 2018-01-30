#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
const int maxc = 100005;

int a[maxn];
int C[maxc];
int c[maxn], d[maxn];
int N = maxc;

int lowbit(int x)
{
    return x & (-x);
}

int sum(int x)
{
    int ret = 0;
    while(x > 0){
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int d)
{
    while(x <= N){
        C[x] += d;
        x += lowbit(x);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", a + i);
        }
        memset(C, 0, sizeof(C));
        for(int i = 1; i <= n; i++){
            add(a[i], 1);
            c[i] = sum(a[i] - 1);
        }
        memset(C, 0, sizeof(C));
        for(int i = n; i >= 1; i--){
            add(a[i], 1);
            d[i] = sum(a[i]-1);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            ans += 1LL * c[i] * (n - i - d[i]) + 1LL * (i - c[i] - 1) * d[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
