#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

int n, m, k, p, q, r, MOD;
int a[maxn], maxrating[maxn], cnt[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &MOD);
        for(int i = 1; i <= k; i++){
            scanf("%d", a + i);
        }
        for(int i = k + 1; i <= n; i++){
            a[i] = (p * a[i - 1] + q * i + r) % MOD;
        }
        int A = 0, B = 0;
        for(int i = 1; i <= n - m + 1; i++){
            if(i == 1 || a[i] < a[i - 1]){
                maxrating[i] = 0, cnt[i] = 0;
                for(int j = i; j <= i + m - 1; j++){
                    if(a[j] > maxrating[i]){
                        maxrating[i] = a[j];
                        cnt[i]++;
                    }
                }
            }else{
            }
            A += maxrating[i] ^ i;
            B += cnt[i] ^ i;
        }
        printf("%d %d\n", A, B);
    }
    return 0;
}

