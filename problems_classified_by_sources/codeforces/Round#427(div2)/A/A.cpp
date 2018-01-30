#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int main()
{
    //freopen("test.txt", "r", stdin);
    int s, v1, v2, t1, t2;
    while(~scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2)){
        int a = s * v1 + 2 * t1, b = s * v2 + 2 * t2;
        if(a < b){
            puts("First");
        }
        else if(a > b){
            puts("Second");
        }
        else{
            puts("Friendship");
        }
    }
    return 0;
}
