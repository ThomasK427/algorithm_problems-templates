#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000005;

LL s[maxn];

bool judge(LL x)
{
    if(x % 7 == 0){
        return true;
    }
    while(x){
        if(x % 10 == 7){
            return true;
        }
        x /= 10;
    }
    return false;
}

int main()
{
    s[0] = 0;
    for(LL i = 1; i <= 1000000; i++){
        if(!judge(i)){
            s[i] = s[i - 1] + i * i;
        }
        else{
            s[i] = s[i - 1];
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int x;
        scanf("%d", &x);
        printf("%lld\n", s[x]);
    }
    return 0;
}
