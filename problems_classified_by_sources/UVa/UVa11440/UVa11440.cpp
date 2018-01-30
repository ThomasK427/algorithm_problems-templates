#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10000005;
const LL Q = 100000007;

bool valid[maxn];
int prime[maxn];
int tot;
LL phifac[maxn];

void getPrime()
{
    for(int i = 0; i < maxn; i++){
        valid[i] = true;
    }
    tot = 0;
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

void getPhiFac()
{
    getPrime();
    phifac[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            phifac[i] = phifac[i - 1] * LL(i - 1) % Q;
        }
        else{
            phifac[i] = phifac[i - 1] * LL(i) % Q;
        }
    }
}

int main()
{
    getPhiFac();
    LL N, M;
    while((cin >> N >> M) && N && M){
        LL ans = 1;
        for(int i = M + 1; i <= N; i++){
            ans = ans * LL(i) % Q;
        }
        ans = ans * phifac[M] % Q;
        cout << ans - 1 << endl;
    }
    return 0;
}
