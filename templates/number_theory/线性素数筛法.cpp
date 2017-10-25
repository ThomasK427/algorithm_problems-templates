#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

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
    getPrime(100);
    return 0;
}
