#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

bool valid[maxn];
int prime[maxn];
int ar[maxn];
int s[maxn];
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

bool IsPrime(int x)
{
    if(x < maxn){
        return valid[x];
    }
    int m = int(sqrt(x)) + 1;
    for(int i = 1; i <= tot; i++){
        if(x % prime[i] == 0){
            return false;
        }
        if(prime[i] > m){
            break;
        }
    }
    return true;
}

int main()
{
    getPrime();
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
            s[i] = s[i-1] + ar[i];
        }
        bool flag = false;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= n - i + 1; j++){
                if(IsPrime(s[j + i - 1] - s[j - 1])){
                    flag = true;
                    printf("Shortest primed subsequence is length %d:", i);
                    for(int k = j; k <= j + i - 1; k++){
                        printf(" %d", ar[k]);
                    }
                    putchar('\n');
                    goto HERE;
                }
            }
        }
        HERE:;
        if(!flag){
            puts("This sequence is anti-primed.");
        }
    }
    return 0;
}
