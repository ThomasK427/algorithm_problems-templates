#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char str[maxn];
int ar[maxn], sr[maxn], d[maxn], mr[maxn], u[maxn], v[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        scanf("%s", str + 1);
        ar[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
            if(str[i] == ')'){
                sr[i] = sr[i - 1] + ar[i];
            }
            else{
                sr[i] = sr[i - 1];
            }
        }
        memset(u, 0, sizeof(u));
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= n; i++){
            u[i] = u[i - 1] + (str[i] == ')');
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(u[j] == i){
                    v[i] = j;
                    break;
                }
            }
            if(v[i] == 0){
                v[i] = v[i - 1];
            }
        }
        memset(d, 0, sizeof(d));
        memset(mr, 0, sizeof(mr));
        int cnt = 0, ans = 0;
        for(int p = n; p >= 1; p--){
            if(str[p] == '('){
                int c = 0;
                for(int i = p; i <= n - cnt; i++){
                    if(i > p && str[i] == '('){
                        c++;
                    }
                    //cout << v[u[i]+c] << " " << i + c << " " << i << " " << c << endl;
                    d[i] = ar[p] * (sr[v[u[i]+c]] - sr[p]) + mr[i + 1];
                }
                for(int i = n; i >= 1; i--){
                    mr[i] = max(mr[i + 1], d[i]);
                }
                ans = mr[p];
                //cout << ans << endl;
                cnt++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
