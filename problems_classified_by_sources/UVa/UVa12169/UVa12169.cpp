#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int Q = 10001;

LL x[maxn];
LL y[maxn];

void extgcd(LL A, LL B, LL& d, LL& x, LL& y){
    if(!B){
        d = A;
        x = 1;
        y = 0;
    }
    else{
        extgcd(B, A % B, d, y, x);
        y -= x * (A / B);
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", x + i);
    }
    LL a = 0, b;
    for(a = 0; a <= 10000; a++){
        LL A = a + 1, B = x[1] - a * a * x[0], d, u, v;
        extgcd(A, Q, d, u, v);
        if(B % d != 0)continue;
        b = u * B / d;
        bool flag = true;
        y[0] = (a * x[0] + b) % Q;
        for(int i = 1; i < T; i++){
            if((a * y[i-1] + b) % Q != x[i]){
                flag = false;
                break;
            }
            y[i] = (a * x[i] + b) % Q;
        }
        if(flag)break;
        else continue;
    }
    for(int i = 0; i < T; i++){
        printf("%lld\n", y[i]);
    }
    return 0;
}
