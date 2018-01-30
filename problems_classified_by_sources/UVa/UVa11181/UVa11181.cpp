#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;

int n, r;
double p[maxn];
double t[maxn];
double sum;
bool used[maxn];

void dfs(int k, double cur, int cnt){
    if(k >= n){
        if(cnt == r){
            sum += cur;
            for(int i = 0; i < n; i++){
                if(used[i]){
                    t[i] += cur;
                }
            }
        }
    }
    else{
        if(cnt + n - k - 1 >= r){
            used[k] = false;
            dfs(k + 1, cur * (1.0 - p[k]), cnt);
        }
        if(cnt < r){
            used[k] = true;
            dfs(k + 1, cur * p[k], cnt + 1);
        }
    }
}

int main()
{
    int kase = 0;
    while(~scanf("%d%d", &n, &r) && (n || r)){
        for(int i = 0; i < n; i++){
            scanf("%lf", p + i);
        }
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; i++){
            t[i] = 0.0;
        }
        sum = 0.0;
        dfs(0, 1.0, 0);
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < n; i++){
            printf("%.6f\n", t[i] / sum);
        }
    }
    return 0;
}
