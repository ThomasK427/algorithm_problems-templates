#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

struct Node{
    double a, b;
}E[maxn];

inline double dist(int i, int j){
    return sqrt((E[i].a - E[j].a) * (E[i].a - E[j].a) + (E[i].b - E[j].b) * (E[i].b - E[j].b));
}

double dp[maxn][maxn];
int n;

double d(int i, int j){
    double& ans = dp[i][j];
    if(ans > 0){
        return ans;
    }
    if(i == n - 1){
        ans = dist(i, n) + dist(j, n);
    }
    else{
        ans = min(d(i + 1, j) + dist(i, i + 1), d(i + 1, i) + dist(j, i + 1));
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n)){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = -1.0;
            }
        }
        if(n == 1){
            puts("0.00");
            continue;
        }
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf", &E[i].a, &E[i].b);
        }
        printf("%.2f\n", dist(1, 2) + d(2, 1));
    }
    return 0;
}
