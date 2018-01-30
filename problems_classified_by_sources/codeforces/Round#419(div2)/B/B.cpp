/*

题目意思是：有很多个区间相互重叠，查询时给出一个区间，问该区间中重叠次数超过K的点有几个
先处理区间重叠：每给出一个区间，将它的左端点++，右端点右边的一个点--
计算前缀和即可得到每个点重叠的次数
再处理查询：将重叠次数大于等于k的点置为1，小于k的点置为0
计算前缀和，查询时将区间右端点对应的前缀和减去区间左端点左边一个点对应的前缀和即得满足条件的点的个数

*/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;

int ar[maxn], br[maxn], cr[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k, q, a, b;
    while(~scanf("%d%d%d", &n, &k, &q)){
        memset(ar, 0, sizeof(ar));
        memset(br, 0, sizeof(br));
        memset(cr, 0, sizeof(cr));
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a, &b);
            ar[a]++;
            ar[b+1]--;
        }
        int s = 0;
        for(int i = 0; i < maxn; i++){
            s += ar[i];
            br[i] = s;
            if(br[i] >= k){
                br[i] = 1;
            }
            else{
                br[i] = 0;
            }
        }
        s = 0;
        for(int i = 0; i < maxn; i++){
            s += br[i];
            cr[i] = s;
        }
        cr[0] = 0;
        while(q--){
            scanf("%d%d", &a, &b);
            printf("%d\n", cr[b] - cr[a-1]);
        }
    }
    return 0;
}
