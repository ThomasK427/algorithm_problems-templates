#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000005;

bool valid[maxn];
int prime[maxn];
int tot;

void getPrime(){
    for(int i = 2; i < maxn; i++){
        valid[i] = true;
    }
    tot = 0;
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] < maxn; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

int main()
{
    getPrime();
    int T;
    scanf("%d", &T);
    while(T--){
        LL n, m = 1;
        scanf("%lld", &n);
        if(n == 1){
            puts("2");
            continue;
        }
        for(int i = 1; prime[i] <= n; i++){
            LL tmp = prime[i];
            while(tmp <= n){
                tmp *= prime[i];
            }
            tmp /= prime[i];
            m = max(m, (n / tmp + 1) * tmp);
        }
        printf("%lld\n", m);
    }
    return 0;
}
