#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;

bool valid[maxn];
int prime[maxn];
int tot;

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
        for(int j = i; (j <= tot) && (i * prime[j] < maxn); j += i){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0)break;
        }
    }
}

bool check(int x)
{
    int m = int(sqrt(x)) + 1;
    for(int i = 1; prime[i] <= m && prime[i] < x; i++){
        if(x % prime[i] == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    getPrime();
    int N, x;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &x);
        if(check(x)){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}
