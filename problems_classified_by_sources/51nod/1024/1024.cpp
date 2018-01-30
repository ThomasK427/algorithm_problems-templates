#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q1 = 1e9 + 7;
const LL Q2 = 1e9 + 9;

set<LL> st;

LL qpow(LL a, LL n, LL Q)
{
    LL base = a, res = 1;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        n >>= 1;
        base = base * base % Q;
    }
    return res;
}

int main()
{
    LL m, n, a, b;
    scanf("%lld%lld%lld%lld", &m, &n, &a, &b);
    for(LL i = b; i <= b + m - 1; i++){
        for(LL j = a; j <= a + n - 1; j++){
            st.insert(qpow(j, i, Q1) * Q1 + qpow(j, i, Q2));
        }
    }
    printf("%d\n", int(st.size()));
    return 0;
}

