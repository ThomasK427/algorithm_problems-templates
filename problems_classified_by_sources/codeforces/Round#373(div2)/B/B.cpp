/*

修改之后的序列可能有两种情况：brbrbrbr...和rbrbrbrb...
将修改之前的字符串和修改之后的字符串比较，同一个位置上不同的字符在str中可能是b或r两种情况
即需要把b改成r和需要把r改成b两种情况
用cnt1和cnt2记录需要把b改成r的个数和需要把r改成b的个数
设cnt1 > cnt2
则需要cnt2次交换操作和cnt1-cnt2次重涂操作
共需cnt1次操作
cnt2 >= cnt1时共需cnt2次操作
则把原序列改成brbrbr...共需ans1 = max(cnt1, cnt2)次操作
改成rbrbrbr...共需ans2次操作
输出min(ans1, ans2)

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
