#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int ar[maxn], var[maxn], lc[maxn], rc[maxn];
int m = 0, n = 0;

void dfs(int k){
    for(int i = 0; i < 1; i++){
        printf("%d%c", var[k], ++m == n ? '\n' : ' ');
    }
    if(lc[k] != -1){
        dfs(lc[k]);
    }
    if(rc[k] != -1){
        dfs(rc[k]);
    }
}

int main()
{
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    int x;
    while(~scanf("%d", &x)){
        ar[++n] = x;
    }
    var[1] = ar[1];
    int idx = 1, num = n;
    for(int i = 2; i <= num; i++){
        x = ar[i];
        int p = 1;
        while(true){
            if(x == var[p]){
                n--;
                break;
            }
            else if(x > var[p]){
                if(rc[p] == -1){
                    var[++idx] = x;
                    rc[p] = idx;
                    break;
                }
                else{
                    p = rc[p];
                }
            }
            else{
                if(lc[p] == -1){
                    var[++idx] = x;
                    lc[p] = idx;
                    break;
                }
                else{
                    p = lc[p];
                }
            }
        }
    }
    dfs(1);
    return 0;
}
