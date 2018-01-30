#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 500005;
int ar[maxn];

inline void read(int &x) {
    x = 0;
    char c;
    do{
        c = getchar();
    } while (c < '0' || c > '9');
    do{
        x = x * 10 + c - '0';
        c = getchar();
    } while (c >= '0' && c <= '9');
}

int main()
{
    int n;
    read(n);
    for(int i = 0; i < n; i++){
        read(ar[i]);
    }
    sort(ar, ar + n);
    ar[n] = INF;
    int m = n / 2, p = m, ans = n;
    for(int i = 0; i < m; i++){
        int pos = lower_bound(ar + p, ar + n, 2 * ar[i]) - ar;
        if(pos < n){
            ans--;
            p = pos + 1;
        }
        else{
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
