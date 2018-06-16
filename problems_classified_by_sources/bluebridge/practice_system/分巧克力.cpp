#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

LL h[maxn], w[maxn];
int N;
LL K;

bool check(LL x){
    LL sum = 0;
    for(int i = 0; i < N; i++){
        sum += (h[i] / x) * (w[i] / x);
        if(sum >= K){
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%lld", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld", h + i, w + i);
    }
    LL low = 1, high = 100000;
    while(low < high){
        LL mid = low + high + 1 >> 1;
        if(check(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    printf("%lld\n", low);
    return 0;
}
