#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int p, y;
    scanf("%d%d", &p, &y);
    bool flag = false;
    while(y > p){
        bool ok = true;
        for(int i = 2; i * i <= y && i <= p; i++){
            if(y % i == 0){
                ok = false;
                break;
            }
        }
        if(ok){
            printf("%d\n", y);
            flag = true;
            break;
        }
        else{
            y--;
        }
    }
    if(!flag){
        puts("-1");
    }
    return 0;
}
