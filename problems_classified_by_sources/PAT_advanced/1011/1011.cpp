#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;

double g[maxn][maxn];

int main()
{
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            scanf("%lf", &g[i][j]);
        }
    }
    double ans = 1;
    for(int i = 1; i <= 3; i++){
        int t = 1;
        for(int j = 1; j <= 3; j++){
            if(g[i][j] > g[i][t]){
                t = j;
            }
        }
        if(t == 1){
            printf("W ");
        }
        else if(t == 2){
            printf("T ");
        }
        else{
            printf("W ");
        }
        ans *= g[i][t];
    }
    ans = (ans * 0.65 - 1) * 2 + 0.0005;
    printf("%.2f\n", ans);
    return 0;
}
