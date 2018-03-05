#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int n, a1 = 0, b1 = 0, c1 = 0;
int ar[maxn];

int f(int c2){
    int a2 = a1 - c1 + c2, b2 = b1 + 2 * c1 - 2 * c2;
    if(a2 < 0 || b2 < 0){
        return INF;
    }
    else{
        return min(a1, a2) + min(b1, b2) + min(c1, c2);
    }
}

int main()
{
    scanf("%d", &n);
    int minx = INF, maxx = -INF;
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
        minx = min(minx, ar[i]);
        maxx = max(maxx, ar[i]);
    }
    if(maxx - minx < 2){
        printf("%d\n", n);
        for(int i = 0; i < n; i++){
            printf("%d%c", ar[i], i == n - 1 ? '\n' : ' ');
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(ar[i] == minx){
                a1++;
            }
            else if(ar[i] == minx + 1){
                b1++;
            }
            else{
                c1++;
            }
        }
        int minf = n, c2 = c1;
        for(int i = 0; i <= n; i++){
            if(f(i) < minf){
                minf = f(i);
                c2 = i;
            }
        }
        int a2 = a1 - c1 + c2, b2 = b1 + 2 * c1 - 2 * c2;
        for(int i = 0; i < n; i++){
            if(i < a2){
                ar[i] = minx;
            }
            else if(i < a2 + b2){
                ar[i] = minx + 1;
            }
            else{
                ar[i] = minx + 2;
            }
        }
        printf("%d\n", minf);
        for(int i = 0; i < n; i++){
            printf("%d%c", ar[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
