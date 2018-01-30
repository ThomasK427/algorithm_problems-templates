#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 200005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, a, b, c;
    while(~scanf("%d%d%d", &n, &a, &b)){
        for(int i = 0; i < n; i++){
            scanf("%d", ar + i);
        }
        c = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ar[i] == 1){
                if(a > 0){
                    a--;
                }
                else if(b > 0){
                    b--;
                    c++;
                }
                else if(c > 0){
                    c--;
                }
                else{
                    ans++;
                }
            }
            else{
                if(b > 0){
                    b--;
                }
                else{
                    ans += 2;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
