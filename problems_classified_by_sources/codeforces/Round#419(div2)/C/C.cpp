/*

题意是给定一个矩阵：多次使用对某一行整体减一或对某一列整体减一的操作，使矩阵变为零矩阵，给出操作次数最少的方案的具体的步骤
若先对行逐行进行减一操作，再对列逐列进行减一操作，最终一定可以化为零矩阵或判定无解，但这样操作次数不一定最少
如
1 1
1 1
1 1
先行后列需要三次操作，先列后行需要两次操作
因此需要进行预处理：将矩阵整体减去矩阵元素中的最小值
若行数小于列数，先行后列进行预处理；若列数小于行数，先列后行进行预处理
预处理之后，先行后列和先列后行所需的操作步数相同，可以选择先行后列
若行数小于列数，预处理过程可以合并到正式处理过程，这样只需预处理列数小于行数的情况
正式处理进行到逐列减一时，没列元素应都相等，若有一列元素不全相等，可以判定为无解

*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
typedef pair<string, int> P;

int g[maxn][maxn];
int r[maxn], c[maxn];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        vector<P> ans;
        int M = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &g[i][j]);
                M = min(M, g[i][j]);
            }
        }
        if(m < n){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < M; k++){
                    ans.push_back(P("col", j + 1));
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    g[i][j] -= M;
                }
            }
        }
        for(int i = 0; i < n; i++){
            int minx = INT_MAX;
            for(int j = 0; j < m; j++){
                minx = min(minx, g[i][j]);
            }
            r[i] = minx;
        }
        for(int i = 0; i < n; i++){
            while(r[i] > 0){
                r[i]--;
                ans.push_back(P("row", i + 1));
                for(int j = 0; j < m; j++){
                    g[i][j]--;
                }
            }
        }
        for(int j = 0; j < m; j++){
            c[j] = g[0][j];
            for(int i = 1; i < n; i++){
                if(c[j] != g[i][j]){
                    printf("-1\n");
                    goto END;
                }
            }
        }
        for(int j = 0; j < m; j++){
            while(c[j] > 0){
                c[j]--;
                ans.push_back(P("col", j + 1));
            }
        }
        printf("%d\n", int(ans.size()));
        for(int i = 0; i < int(ans.size()); i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
        END:;
    }
    return 0;
}

