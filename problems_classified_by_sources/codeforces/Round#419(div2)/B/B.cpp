/*

��Ŀ��˼�ǣ��кܶ�������໥�ص�����ѯʱ����һ�����䣬�ʸ��������ص���������K�ĵ��м���
�ȴ��������ص���ÿ����һ�����䣬��������˵�++���Ҷ˵��ұߵ�һ����--
����ǰ׺�ͼ��ɵõ�ÿ�����ص��Ĵ���
�ٴ����ѯ�����ص��������ڵ���k�ĵ���Ϊ1��С��k�ĵ���Ϊ0
����ǰ׺�ͣ���ѯʱ�������Ҷ˵��Ӧ��ǰ׺�ͼ�ȥ������˵����һ�����Ӧ��ǰ׺�ͼ������������ĵ�ĸ���

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
