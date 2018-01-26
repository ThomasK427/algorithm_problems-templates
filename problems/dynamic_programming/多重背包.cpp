/**
* 51nod 1086
*/

/**
*
*有N种物品，每种物品的数量为C1，C2......Cn。从中任选若干件放在
*容量为W的背包里，每种物品的体积为W1，W2......Wn（Wi为整数），
*与之相对应的价值为P1,P2......Pn（Pi为整数）。求背包能够容纳的最大价值。
*
*Input
*
*第1行，2个整数，N和W中间用空格隔开。N为物品的种类，W为背包的容量。(1 <= N <= 100，1 <= W <= 50000)
*第2 - N + 1行，每行3个整数，Wi，Pi和Ci分别是物品体积、价值和数量。(1 <= Wi, Pi <= 10000， 1 <= Ci <= 200)
*
*Output
*
*输出可以容纳的最大价值。
*
*/

/**
*多重背包问题：将一个数量为C的物品分解为数量为1，2，4，8，...，2^k, C - 2^(k+1) + 1的多个背包
*然后当成0-1背包来做
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2005;
const int maxk = 50005;

int c[maxn], w[maxn], p[maxn];
LL dp[maxk];

vector<int> split(int x)
{
    vector<int> v;
    int p = 1;
    while(x >= p){
        v.push_back(p);
        x -= p;
        p *= 2;
    }
    if(x > 0){
        v.push_back(x);
    }
    return v;
}

int main()
{
    int N, W, M = 0, x, y, z;
    scanf("%d%d", &N, &W);
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d", &x, &y, &z);
        vector<int> v = split(z);
        for(int j = 0; j < v.size(); j++){
            w[++M] = x * v[j];
            p[M] = y * v[j];
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + LL(p[i]));
        }
    }
    printf("%lld\n", dp[W]);

    return 0;
}
