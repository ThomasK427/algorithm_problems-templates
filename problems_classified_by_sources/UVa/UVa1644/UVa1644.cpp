#include <bits/stdc++.h>
using namespace std;
const int maxn = 1300005;

//素数筛法O(n)
bool valid[maxn];    //valid[i]记录i是否为素数
int prime[maxn];     //prime[i]记录第i个素数
int tot;    //记录素数的个数

void getPrime(int n){   //打一个小于等于n的素数表
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

int main()
{
    getPrime(1300000);
    int x;
    while(~scanf("%d", &x) && x){
        int p = lower_bound(prime + 1, prime + tot + 1, x) - prime;
        printf("%d\n", prime[p] == x ? 0 : prime[p] - prime[p - 1]);
    }
    return 0;
}
