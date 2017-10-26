#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 1000005;

//O(n)
LL inv[maxn];

void getInv(int n, LL p){   //求1-n模p意义下的逆元，p为质数
    inv[1] = 1;
    for(int i = 2; i <= n; i++){
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
}

int main()
{
    getInv(1000, Q);
    return 0;
}
