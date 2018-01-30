#include <bits/stdc++.h>
using namespace std;
typedef long long L;

int main()
{
    //freopen("test.txt", stdin);
    L n, k;
    while(~scanf("%lld%lld", &n, &k)){
        L u = n / k;
        if(u & 1){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
