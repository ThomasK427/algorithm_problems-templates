/**
* codeforces
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

//求k个不相交的区间能覆盖的最大长度
struct Node{
    LL a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.b != e2.b){
            return e1.b < e2.b;
        }
        else{
            return e1.a < e2.a;
        }
    }
}E[maxn];

LL dp[maxn];    //第0个到第i个区间能覆盖的最大长度

int BinSearch(int low, int high, LL x){
    while(low < high){
        int mid = low + high + 1 >> 1;
        if(E[mid].b < x){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    LL n;
    int k;
    scanf("%lld%d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%lld%lld", &E[i].a, &E[i].b);
    }
    sort(E, E + k);
    dp[0] = E[0].b - E[0].a + 1;
    for(int i = 1; i < k; i++){
        int p = BinSearch(0, i, E[i].a);
        if(E[p].b < E[i].a){
            dp[i] = max(dp[i - 1], dp[p] + E[i].b - E[i].a + 1);
        }
        else{
            dp[i] = max(dp[i - 1], E[i].b - E[i].a + 1);
        }
    }
    printf("%lld\n", n - dp[k - 1]);    //输出的是不能覆盖的最小长度
    return 0;
}
