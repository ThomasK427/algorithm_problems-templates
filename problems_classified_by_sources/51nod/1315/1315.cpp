#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int a[40], b[40];

int main()
{
    LL x, y;
    int N;
    scanf("%d%lld", &N, &x);
    for(int i = 0; i <= 32; i++){
        if(x & (1LL << i)){
            a[i] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        scanf("%lld", &y);
        bool flag = true;
        for(int j = 0; j <= 32; j++){
            if((a[j] == 0) && (y & (1LL << j))){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int j = 0; j <= 32; j++){
                if(y & (1LL << j)){
                    b[j]++;
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= 32; i++){
        if(a[i]){
            ans = min(ans, b[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
