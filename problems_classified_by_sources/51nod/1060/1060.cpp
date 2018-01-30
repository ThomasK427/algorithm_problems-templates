#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100;

bool valid[maxn];
int prime[maxn];
int tot;

void getPrime()
{
    tot = 0;
    for(int i = 0; i < maxn; i++){
        valid[i] = true;
    }
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; (j <= tot) && (i * prime[j] < maxn); j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0)break;
        }
    }
}

LL N;
LL ans = 0x3f3f3f3f3f3f3f3f, sum = 0;

void dfs(int k, LL t, LL s, int lim)
{
    if(s > sum){
        sum = s;
        ans = t;
    }
    if(s == sum && ans > t){
        ans = t;
    }
    if(k > 15){
        return;
    }
    for(int i = 1; i <= lim; i++){
        if(t <= N / prime[k]){
            t *= prime[k];
            dfs(k + 1, t, s * (i + 1), i);
        }
        else{
            break;
        }
    }
}

int main()
{
    getPrime();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lld", &N);
        ans = 0x3f3f3f3f3f3f3f3f;
        sum = 0;
        dfs(1, 1, 1, int(log(N)) + 1);
        printf("%lld %lld\n", ans, sum);
    }
    return 0;
}
