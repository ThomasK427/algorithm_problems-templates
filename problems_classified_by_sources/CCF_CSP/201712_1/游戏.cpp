#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int n, k;
int ar[maxn];

void inc(int& p){
    p = (p + 1) % n;
    while(ar[p] < 0){
        p = (p + 1) % n;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        ar[i] = i + 1;
    }
    int p = 0, idx = 1;
    for(int i = 1; i <= n - 1; i++){
        while(idx % k != 0 && idx % 10 != k){
            inc(p);
            idx++;
        }
        ar[p] = -1;
        inc(p);
        idx++;
    }
    printf("%d\n", ar[p]);
    return 0;
}
