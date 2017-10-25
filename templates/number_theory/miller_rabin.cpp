#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL qpow(LL a, LL n, LL Q){
    LL base = a % Q, res = 1;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

bool MillerRabinTest(LL n, LL a, LL d){
    if(n == 2){
        return true;
    }
    if(n == a){
        return true;
    }
    if(!(n & 1)){
        return false;
    }
    while(!(d & 1)){
        d >>= 1;
    }
    LL t = qpow(a, d, n);
    while((d != n - 1) && (t != 1) && (t != n - 1)){
        t = t * t % n;
        d <<= 1;
    }
    return t == n - 1 || (d & 1) == 1;
}

bool isPrime(LL n){
    if(n < 2){
        return false;
    }
    LL ar[] = {2, 3, 61};   //为增加准确率，可增大测试集，测试集中数为素数
    for(int i = 0; i <= 2; i++){
        if(!MillerRabinTest(n, ar[i], n - 1)){
            return false;
        }
    }
    return true;
}

int main()  //HDU2138
{
    int N;
    while(~scanf("%d", &N)){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            LL x;
            scanf("%lld", &x);
            if(isPrime(x)){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
