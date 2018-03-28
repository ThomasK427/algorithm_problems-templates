#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int ar[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int c1 = 0, c2 = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
        if(ar[i] == 0){
            c1++;
        }
        else if(ar[i] < 0){
            c2++;
        }
    }
    if(c1 + c2 == n && c1 > 0){
        printf("0 0 0\n");
        return 0;
    }
    int ms = 0, ts = 0, ss = 1, s = 1, t = n;
    for(int i = 1; i <= n; i++){
        ts += ar[i];
        if(ts > ms){
            ms = ts;
            s = ss;
            t = i;
        }
        else if(ts < 0){
            ts = 0;
            ss = i + 1;
        }
    }
    printf("%d %d %d\n", ms, ar[s], ar[t]);
    return 0;
}
