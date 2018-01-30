#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 5;

char str[maxn];
int k;

int main()
{
    //freopen("test.txt", "r", stdin);
    while(~scanf("%d %s", &k, str)){
        int sum = 0, len = strlen(str), ans, p;
        for(int i = 0; i < len; i++){
            sum += str[i] - '0';
            if(sum >= k){
                ans = 0;
                goto HERE;
            }
        }
        k -= sum;
        sort(str, str + len);
        ans = 0, p = 0;
        while(k > 0){
            k -= 9 - (str[p++] - '0');
            ans++;
        }
        HERE:;
        printf("%d\n", ans);
    }

    return 0;
}

