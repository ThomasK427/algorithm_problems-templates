#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxm = 1000005;
const int m = 1000000;

int ar[maxn];
bool vis[maxm];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    vis[0] = true;
    int cnt = 0, last = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            if(i >= ar[j]){
                vis[i] |= vis[i - ar[j]];
            }
        }
        if(!vis[i]){
            cnt++;
            last = i;
        }
    }
    if(m - last >= 10000){
        printf("%d\n", cnt);
    }
    else{
        puts("INF");
    }
    return 0;
}
