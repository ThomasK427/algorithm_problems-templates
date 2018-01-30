//#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long LL;
const int maxn = 1000005;

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

int main()
{
    getPrime();
    LL N;
    while(~scanf("%lld", &N) && N){
        if(N == 1){
            puts("0");
            continue;
        }
        LL ans = N, M = N;
        for(int i = 1; (i <= tot) && (prime[i] <= N) && (prime[i] * prime[i] <= M); i++){
            if(N % prime[i] == 0){
                ans = ans / prime[i] * (prime[i] - 1);
                while(N % prime[i] == 0){
                    N /= prime[i];
                }
            }
        }
        if(N > 1){
            ans = ans / N * (N - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
