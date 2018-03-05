#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    a += n - 1;
    b += n - 1;
    for(int i = 1; ; i++){
        a /= 2;
        b /= 2;
        if(a == b){
            if(a == 1){
                puts("Final!");
            }
            else{
                printf("%d\n", i);
            }
            break;
        }
    }
    return 0;
}
