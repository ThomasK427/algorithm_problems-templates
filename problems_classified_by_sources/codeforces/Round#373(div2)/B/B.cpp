/*

�޸�֮������п��������������brbrbrbr...��rbrbrbrb...
���޸�֮ǰ���ַ������޸�֮����ַ����Ƚϣ�ͬһ��λ���ϲ�ͬ���ַ���str�п�����b��r�������
����Ҫ��b�ĳ�r����Ҫ��r�ĳ�b�������
��cnt1��cnt2��¼��Ҫ��b�ĳ�r�ĸ�������Ҫ��r�ĳ�b�ĸ���
��cnt1 > cnt2
����Ҫcnt2�ν���������cnt1-cnt2����Ϳ����
����cnt1�β���
cnt2 >= cnt1ʱ����cnt2�β���
���ԭ���иĳ�brbrbr...����ans1 = max(cnt1, cnt2)�β���
�ĳ�rbrbrbr...����ans2�β���
���min(ans1, ans2)

*/

#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

char str[maxn];
char s1[maxn], s2[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", str);
        for(int i = 0; i < n; i++){
            if(i & 1){
                s1[i] = 'r';
                s2[i] = 'b';
            }
            else{
                s1[i] = 'b';
                s2[i] = 'r';
            }
        }
        int ans1 = 0, ans2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(str[i] != s1[i]){
                if(s1[i] == 'b'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        ans1 = max(cnt1, cnt2);
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(str[i] != s2[i]){
                if(s2[i] == 'b'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        ans2 = max(cnt1, cnt2);
        printf("%d\n", min(ans1, ans2));
    }

    return 0;
}
