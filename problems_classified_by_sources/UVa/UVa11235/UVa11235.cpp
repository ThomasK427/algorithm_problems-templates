#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int ar[maxn];
int value[maxn], cnt[maxn], num[maxn], lft[maxn], rht[maxn];
int d[maxn][20];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, q;
    while(~scanf("%d", &n) && n){
        scanf("%d", &q);
        ar[0] = -0x3f3f3f3f;
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
        }
        int p = 0;
        value[p] = ar[1];
        cnt[p] = 1;
        num[1] = p;
        lft[1] = 1;
        rht[1] = upper_bound(ar, ar + n + 1, ar[1]) - ar - 1;
        for(int i = 2; i <= n; i++){
            if(ar[i] == ar[i-1]){
                cnt[p]++;
                num[i] = p;
                lft[i] = lft[i-1];
                rht[i] = rht[i-1];
            }
            else{
                p++;
                value[p] = ar[i];
                cnt[p] = 1;
                num[i] = p;
                lft[i] = i;
                rht[i] = upper_bound(ar, ar + n + 1, ar[i]) - ar - 1;
            }
        }
        p++;
        for(int i = 0; i < p; i++){
            d[i][0] = cnt[i];
        }
        for(int j = 1; (1 << j) <= p; j++){
            for(int i = 0; i + (1 << j) - 1 < p; i++){
                d[i][j] = max(d[i][j-1], d[i + (1 << (j-1))][j-1]);
            }
        }
        while(q--){
            int i, j;
            scanf("%d%d", &i, &j);
            if(num[i] == num[j]){
                printf("%d\n", j - i + 1);
            }
            else if(num[i] + 1 == num[j]){
                printf("%d\n", max(rht[i] - i + 1, j - lft[j] + 1));
            }
            else{
                int m = max(rht[i] - i + 1, j - lft[j] + 1);
                int ip = num[i] + 1, jp = num[j] - 1;
                int k = 0;
                while((1 << (k + 1)) <= jp - ip + 1){
                    k++;
                }
                m = max(m, max(d[ip][k], d[jp - (1 << k) + 1][k]));
                printf("%d\n", m);
            }
        }
    }
    return 0;
}
