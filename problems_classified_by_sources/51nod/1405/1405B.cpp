/**
*����һ���޸�������������n���ڵ㣬�ڵ��Ŵ�1��n, ����������֮��ľ��루���·����֮�͡�
*Input
*
*��һ�а���һ��������n (n <= 100000)����ʾ�ڵ������
*����(n - 1)�У�ÿ������������ʾ���ıߡ�
*
*Output
*
*ÿ��һ����������i(i = 1,2,...n)�б�ʾ���нڵ㵽��i����ľ���֮�͡�
**/

//������u�Ĵ���֪�����������ڵĽ��v�Ĵ𰸿���ans[v] = ans[u] + n - 2 * cnt[v]�ó�
//O(n)

#include <stdio.h>
#include <vector>
typedef long long LL;
using namespace std;
const int maxn = 100005;

vector<int> g[maxn];
LL cnt[maxn], ans[maxn];
int n;

LL dfs(int k, int fa){  //��ÿ��������ģ
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

LL dfs1(int k, int fa){ //�������㵽�����ľ���֮��
    LL res = cnt[k];
    for(int i = 0; i < g[k].size(); i++){
        int v = g[k][i];
        if(v != fa){
            res += dfs1(v, k);
        }
    }
    return res;
}

LL dfs2(int k, int fa){ //��ÿ����㵽�������ľ���֮��
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
