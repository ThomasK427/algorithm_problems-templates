/*

�����Ǹ���һ�����󣺶��ʹ�ö�ĳһ�������һ���ĳһ�������һ�Ĳ�����ʹ�����Ϊ����󣬸��������������ٵķ����ľ���Ĳ���
���ȶ������н��м�һ�������ٶ������н��м�һ����������һ�����Ի�Ϊ�������ж��޽⣬����������������һ������
��
1 1
1 1
1 1
���к�����Ҫ���β��������к�����Ҫ���β���
�����Ҫ����Ԥ���������������ȥ����Ԫ���е���Сֵ
������С�����������к��н���Ԥ����������С�����������к��н���Ԥ����
Ԥ����֮�����к��к����к�������Ĳ���������ͬ������ѡ�����к���
������С��������Ԥ������̿��Ժϲ�����ʽ������̣�����ֻ��Ԥ��������С�����������
��ʽ������е����м�һʱ��û��Ԫ��Ӧ����ȣ�����һ��Ԫ�ز�ȫ��ȣ������ж�Ϊ�޽�

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

