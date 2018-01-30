#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005007;

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
        for(int j = 1; j <= tot && i * prime[j] < maxn; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0)break;
        }
    }
}

int main()
{
    getPrime();
    int N;
    scanf("%d", &N);
    int p = lower_bound(prime + 1, prime + tot + 1, N) - prime;
    while(!valid[p])p++;
    printf("%d\n", prime[p]);
    return 0;
}
