/**
*51nod 1405
*给定一棵无根树，假设它有n个节点，节点编号从1到n, 求任意两点之间的距离（最短路径）之和。
*Input
*
*第一行包含一个正整数n (n <= 100000)，表示节点个数。
*后面(n - 1)行，每行两个整数表示树的边。
*
*Output
*
*每行一个整数，第i(i = 1,2,...n)行表示所有节点到第i个点的距离之和。
*/

//如果结点u的答案已知，则与它相邻的结点v的答案可由ans[v] = ans[u] + n - 2 * cnt[v]得出
//O(n)

#include <stdio.h>
#include <vector>
typedef long long LL;
using namespace std;
const int maxn = 100005;

vector<int> g[maxn];
LL cnt[maxn], ans[maxn];
int n;

LL dfs(int k, int fa){  //求每个子树规模
    LL& res = cnt[k];
    res = 1;
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            res += dfs(v, k);
        }
    }
    return res;
}

LL dfs1(int k, int fa){ //求其他点到树根的距离之和
    LL res = cnt[k];
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            res += dfs1(v, k);
        }
    }
    return res;
}

LL dfs2(int k, int fa){ //求每个结点到其他结点的距离之和
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            ans[v] = ans[k] + n - 2 * cnt[v];
            dfs2(v, k);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    ans[1] = dfs1(1, -1) - n;
    dfs2(1, -1);
    for(int i = 1; i <= n; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}
