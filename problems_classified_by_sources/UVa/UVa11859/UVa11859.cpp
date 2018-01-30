#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

bool valid[maxn];
int prime[maxn];
int tot;

void getPrime(int n){
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

int cot(int x){
    int res = 0;
    for(int i = 1; prime[i] <= x; i++){
        while(x % prime[i] == 0){
            res++;
            x /= prime[i];
        }
    }
    return res;
}

int main()
{
    getPrime(10007);
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d%d", &N, &M);
        int nim = 0;
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = 0; j < M; j++){
                int x;
                scanf("%d", &x);
                sum += cot(x);
            }
            nim ^= sum;
        }
        if(nim){
            printf("Case #%d: YES\n", ++kase);
        }
        else{
            printf("Case #%d: NO\n", ++kase);
        }
    }
    return 0;
}
