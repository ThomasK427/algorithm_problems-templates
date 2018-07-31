#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 70000005;

int n, m, k;
LL p, q, r, MOD;
LL a[maxn];

struct Node{
    LL value;
    int index;
}que[maxn];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%lld%lld%lld%lld", &n, &m, &k, &p, &q, &r, &MOD);
        for(int i = 1; i <= k; i++){
            scan_d(a[i]);
        }
        for(int i = k + 1; i <= n; i++){
            a[i] = ((p * a[i - 1] % MOD + q * i % MOD) % MOD + r) % MOD;
        }
        int s = 0, t = 0;
        LL A = 0, B = 0;
        for(int i = n; i >= 1; i--){
            if(s == t){
                que[t].value = a[i];
                que[t].index = i;
                t++;
            }else{
                while(t > s){
                    if(a[i] >= que[t - 1].value){
                        t--;
                    }else{
                        que[t].value = a[i];
                        que[t].index = i;
                        t++;
                        break;
                    }
                }
            }
            while(s < t){
                if(que[s].index > i + m - 1){
                    s++;
                }else{
                    break;
                }
            }
            if(i <= n - m + 1){
                A += que[s].value ^ i;
                B += (t - s) ^ i;
            }
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}

