#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

LL s[maxn], sum[maxn];

int main()
{
    LL n, A, B;
    scanf("%lld%lld%lld", &n, &A, &B);
    for(int i = 1; i <= n; i++){
        scanf("%lld", s + i);
    }
    sort(s + 2, s + n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + s[i];
    }
    for(int i = n; i >= 1; i--){
        if(s[1] * A >= sum[i] * B){
            printf("%d\n", n - i);
            break;
        }
    }
    return 0;
}

