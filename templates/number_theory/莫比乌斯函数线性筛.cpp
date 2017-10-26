#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

bool valid[maxn];   //valid[i]表示i是否为素数
int prime[maxn];    //prime[i]表示第i个素数
int mob[maxn];      //mob[i]表示i的莫比乌斯函数值
int tot;

void getMobius(int n){
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    mob[1] = 1;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            prime[++tot] = i;
            mob[i] = -1;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                mob[i * prime[j]] = 0;
                break;
            }
            mob[i * prime[j]] = -mob[i];
        }
    }
}

int main()
{
    getMobius(1000000);
    int n;
    scanf("%d", &n);
    printf("%d\n", mob[n]);
    return 0;
}
