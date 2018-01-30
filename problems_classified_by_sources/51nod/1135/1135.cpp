#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;

LL qpow(LL a, LL n, LL Q)
{
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

bool g_test(LL g, LL p)
{
    for(int i = 0; i < v.size(); i++){
        if(qpow(g, (p - 1) / v[i], p) == 1){
            return false;
        }
    }
    return true;
}

int main()
{
    LL p;
    scanf("%lld", &p);
    LL x = p - 1;
    for(LL i = 2; i <= x / i; i++){
        if(x % i == 0){
            v.push_back(i);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x > 1){
        v.push_back(x);
    }
    LL g = 1;
    while(true){
        if(g_test(g, p)){
            printf("%lld\n", g);
            break;
        }
        g++;
    }
    return 0;
}
