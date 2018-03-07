#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    LL a, b;
    scanf("%lld%lld", &a, &b);
    while(a * b){
        if(a == 0 && b == 0){
            break;
        }
        else if(a >= 2 * b){
            a %= (2 * b);
        }
        else if(b >= 2 * a){
            b %= (2 * a);
        }
        else{
            break;
        }
    }
    printf("%lld %lld", a, b);
    return 0;
}
