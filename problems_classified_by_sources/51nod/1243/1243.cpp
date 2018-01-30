#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

LL p[maxn];
int N;
LL X, M;

bool check(LL y){
    LL cur = 0;
    for(int i = 0; i < N; i++){
        if(cur + X > p[i] + y){
            return false;
        }
        else{
            cur = max(p[i] - y, cur + X) + X;
            if(cur > M){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d%lld%lld", &N, &X, &M);
    for(int i = 0; i < N; i++){
        scanf("%lld", p + i);
    }
    if(2 * X * N > M){
        puts("-1");
        return 0;
    }
    LL low = 0, high = M;
    while(low < high){
        LL mid = (low + high) >> 1;
        if(check(mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    printf("%lld\n", high);
    return 0;
}
