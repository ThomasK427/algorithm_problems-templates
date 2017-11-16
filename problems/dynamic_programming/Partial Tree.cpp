/**
*Partial Tree icpc2015长春 HDU5534
*完全背包问题
*n个结点连成一棵树，共n-1条边，总度数为2(n-1)
*其中每个点度数至少为1
*每个点预先分配1度，总价值为n * f(1)
*其余n-2度任意分配给n个点，可以看成一个完全背包问题
*共有n-2个物品，体积分别为1，2，...，n - 2
*其中体积为i的物品价值为f(i + 1) - f(1)，背包总容量为n - 2
*将体积为i的物品装入背包相当于用一个度数为i + 1的结点置换一个度数为1的结点，
*由此将获得f(i + 1) - f(1)的价值
*由于剩下的n-2度必须完全分配给n个结点，背包必须装满
*要求背包装满时只需将dp数组初始化为-INF即可
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2020;

int f[maxn], value[maxn], dp[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            scanf("%d", f + i);
        }
        for(int i = 1; i < n - 1; i++){
            value[i] = f[i + 1] - f[1];
        }
        for(int i = 1; i <= n; i++){
            dp[i] = -INF;
        }
        dp[0] = n * f[1];
        for(int i = 1; i < n - 1; i++){
            for(int j = i; j <= n - 2; j++){
                dp[j] = max(dp[j], dp[j - i] + value[i]);
            }
        }
        printf("%d\n", dp[n - 2]);
    }
    return 0;
}
