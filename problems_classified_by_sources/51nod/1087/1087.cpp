#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL f(LL n)
{
    return n * (n + 1) / 2 + 1;
}

bool judge(LL x)
{
    LL low = 0, high = x;
    while(low <= high){
        LL mid = (low + high) >> 1;
        if(f(mid) < x){
            low = mid + 1;
        }
        else if(f(mid) > x){
            high = mid - 1;
        }
        else{
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL x;
        scanf("%lld", &x);
        printf("%d\n", judge(x));
    }
    return 0;
}
