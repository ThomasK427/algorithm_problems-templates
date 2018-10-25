#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

LL solve(LL a){
    LL ans = 1;
    while(a){
        if(a & 1){
            ans *= 2;
        }
        a /= 2;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        LL a;
        scanf("%lld", &a);
        printf("%lld\n", solve(a));
    }
    return 0;
}
