#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1000005;
const ull Q = 233;

char s[maxn];
ull xp[maxn];
ull h[maxn];

int main()
{
    xp[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        xp[i] = xp[i - 1] * Q;
    }
    while(gets(s) && s[0] != '.'){
        int n = strlen(s);
        h[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            h[i] = h[i + 1] * Q + ull(s[i] - 'a' + 1);
        }
        int ans = 1;
        for(int i = 1; i <= n; i++){
            if(n % i != 0){
                continue;
            }
            bool flag = true;
            ull hb = h[0] - h[i] * xp[i];
            for(int j = i; j < n; j += i){
                ull hs = h[j] - h[j + i] * xp[i];
                if(hb != hs){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = n / i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
