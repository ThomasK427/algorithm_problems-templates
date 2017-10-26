#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

bool valid[maxn];
int prime[maxn];
int divisor[maxn];      //divisor[i]表示i的约数个数
int d[maxn];
int tot;

void getDivisor(int n){
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    divisor[1] = 1;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            prime[++tot] = i;
            divisor[i] = 2;
            d[i] = 1;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                divisor[i * prime[j]] = divisor[i] / (d[i] + 1) * (d[i] + 2);
                d[i * prime[j]] = d[i] + 1;
                break;
            }
            divisor[i * prime[j]] = divisor[i] * 2;
            d[i * prime[j]] = 1;
        }
    }
}

int main()
{
    getDivisor(1000);
    for(int i = 1; i <= 1000; i++){
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                cnt++;
            }
        }
        if(cnt != divisor[i]){
            puts("WA");
        }
    }
    return 0;
}
