#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10005;

struct Node{
    LL x, w;
    friend bool operator<(const Node& a, const Node& b){
        return a.x < b.x;
    }
}E[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    LL sum = 0;
    for(int i = 1; i <= N; i++){
        scanf("%lld%lld", &E[i].x, &E[i].w);
        sum += E[i].w;
    }
    sort(E + 1, E + N + 1);
    LL s = 0, p = 0;
    for(int i = 1; i <= N; i++){
        s += E[i].w;
        if(s >= (sum + 1) / 2){
            p = E[i].x;
            break;
        }
    }
    LL ans = 0;
    for(int i = 1; i <= N; i++){
        ans += E[i].w * abs(p - E[i].x);
    }
    printf("%lld\n", ans);
    return 0;
}
