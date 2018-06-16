#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxw = 10005;
const int maxt = 1000005;
const ull Q = 233;

ull xp[maxt];
char W[maxw], T[maxt];
ull h[maxt];

int main()
{
    xp[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        xp[i] = xp[i - 1] * Q;
    }
    int K;
    scanf("%d", &K);
    getchar();
    while(K--){
        gets(W);
        gets(T);
        int m = strlen(W), n = strlen(T);
        ull w = 0;
        for(int i = m - 1; i >= 0; i--){
            w = w * Q + ull(W[i] - 'A' + 1);
        }
        h[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            h[i] = h[i + 1] * Q + ull(T[i] - 'A' + 1);
        }
        int ans = 0;
        for(int i = 0; i <= n - m; i++){
            ull hs = h[i] - h[i + m] * xp[m];
            if(hs == w){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
