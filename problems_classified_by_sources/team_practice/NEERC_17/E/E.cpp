#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;
const int Q = 1000;

int a[maxn], x[maxn * 2], ans[maxn];

int main()
{
    int n, m = 0, k = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    for(int i = 1; i <= n; i++){
        ans[i] = 1;
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(a[i] >= 0){
            x[a[i] + Q]++;
            if(a[i] == 0){
                k++;
            }
        }
        else{
            if(x[-a[i] + Q] > 0){
                x[-a[i] + Q]--;
            }
            else{
                if(x[Q] > 0){
                    ans[++m] = -a[i];
                    x[Q]--;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag){
        puts("Yes");
        for(int i = 1; i <= k; i++){
            printf("%d%c", ans[i], i == k ? '\n' : ' ');
        }
    }
    else{
        puts("No");
    }
    return 0;
}
