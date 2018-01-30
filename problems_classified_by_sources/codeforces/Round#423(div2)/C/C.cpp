#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1000005;

char ans[maxn * 2];
int ar[maxn];
string s[maxn];

struct Node{
    int idx, a, b;
    friend bool operator<(const Node& n1, const Node& n2){
        if(n1.a != n2.a){
            return n1.a < n2.a;
        }
        else{
            return n1.b > n2.b;
        }
    }
}E[maxn], F[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k;
    while(~scanf("%d", &n)){
        memset(ans, 0, sizeof(ans));
        int q = 0;
        for(int i = 0; i < n; i++){
            cin >> s[i] >> k;
            int len = s[i].size();
            for(int j = 0; j < k; j++){
                scanf("%d", ar + j);
                E[q].idx = i;
                E[q].a = ar[j];
                E[q].b = ar[j] + len - 1;
                q++;
            }
        }
        sort(E, E + q);
        F[0] = E[0];
        int r = 1;
        for(int i = 1; i < q; i++){
            if(E[i].b > E[i-1].b){
                F[r++] = E[i];
            }
        }
        int p = 0;
        for(int i = 0; i < r; i++){
            int x = s[F[i].idx].size() - 1;
            for(int j = F[i].b; j >= max(p, F[i].a); j--){
                ans[j] = s[F[i].idx][x];
                x--;
            }
            p = max(p, F[i].b);
        }
        p++;
        for(int i = 1; i < p; i++){
            if(ans[i] == 0){
                ans[i] = 'a';
            }
        }
        ans[p] = '\0';
        printf("%s\n", ans + 1);
    }
    return 0;
}
