#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int bit[maxn], buf[maxn], stmax[maxn], stmin[maxn];
int m;

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        m = 0;
        while(n){
            bit[m++] = n % 10;
            n /= 10;
        }
        reverse(bit, bit + m);
        for(int i = 0; i < m; i++){
            buf[i] = bit[i];
        }
        int p = 0;
        for(int c = 0; c < k; c++){
            while(p < m - 1){
                int q = m;
                for(int i = m - 1; i > p; i--){
                    if(p == 0 && buf[i] == 0){
                        continue;
                    }
                    if(buf[i] < buf[p] && (q == m || buf[i] < buf[q])){
                        q = i;
                    }
                }
                if(q == m){
                    p++;
                }else{
                    swap(buf[p], buf[q]);
                    p++;
                    break;
                }
            }
            if(p == m - 1){
                break;
            }
        }
        for(int i = 0; i < m; i++){
            printf("%d", buf[i]);
        }
        putchar(' ');
        for(int i = 0; i < m; i++){
            buf[i] = bit[i];
        }
        p = 0;
        for(int c = 0; c < k; c++){
            while(p < m - 1){
                int q = m;
                for(int i = m - 1; i > p; i--){
                    if(buf[i] > buf[p] && (q == m || buf[i] > buf[q])){
                        q = i;
                    }
                }
                if(q == m){
                    p++;
                }else{
                    swap(buf[p], buf[q]);
                    p++;
                    break;
                }
            }
            if(p == m - 1){
                break;
            }
        }
        for(int i = 0; i < m; i++){
            printf("%d", buf[i]);
        }
        putchar('\n');
    }
    return 0;
}
