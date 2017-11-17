/**
*zap bzoj1101 洛谷P3455
*莫比乌斯反演，基本上同HDU1695
*利用分块将单次查询的复杂度从O(n)将为O(sqrt(n))
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

bool valid[maxn];
int prime[maxn], mob[maxn], sum[maxn];
int tot;

void getMobius(int n){
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    mob[1] = 1;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            mob[i] = -1;
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j]){
                mob[i * prime[j]] = -mob[i];
            }
            else{
                mob[i * prime[j]] = 0;
                break;
            }
        }
    }
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + mob[i];
    }
}

int main()
{
    getMobius(50000);
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        if(d == 0){
            puts("0");
            continue;
        }
        int p = a / d, q = b / d;
        if(p > q){
            swap(p, q);
        }
        int ans = 0;
        for(int L = 1, R = 0; L <= p; L = R + 1){ //上一次计算到R，所以L从R+1开始
            /**对区间[L, R]内的任一元素i, p / i都相等，q / i都相等
            *设对区间[L, R1]内的任一元素i，p / i = x，对区间[L, R2]内的任一元素i, q / i = y
            *x = p / L, R1 = p / x = p / (p / L), y = q / L, R2 = q / y = q / (q / L)
            *对区间[L, min(R1, R2)]内的任一元素i，p / i都相等(= x = p / L)，q / i都相等(= y = q / L)
            *(p / i)(q / i)都相等(= (p / L)(q / L))，可以作为一块一次计算出来
            */
            R = min(p / (p / L), q / (q / L));
            ans += (sum[R] - sum[L - 1]) * (p / L) * (q / L);
        }
        printf("%d\n", ans);
    }
    return 0;
}
