#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 5;

int ar[maxn];
int br[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m) && n && m){
        for(int i = 0; i < n; i++){
            scanf("%d", ar + i);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", br + i);
        }
        sort(ar, ar + n);
        sort(br, br + m);
        int cur = 0, cost = 0;
        for(int i = 0; i < m; i++){
            if(br[i] >= ar[cur]){
                cost += br[i];
                cur++;
                if(cur == n)break;
            }
        }
        if(cur == n){
            printf("%d\n", cost);
        }
        else{
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}
