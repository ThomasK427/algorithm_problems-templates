#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;

double f[maxn], g[maxn];
int c[maxn][maxn];

double pw(double x, int n){
    double base = x, res = 1;
    while(n){
        if(n & 1){
            res *= base;
        }
        base = base * base;
        n /= 2;
    }
    return res;
}

int main()
{
    for(int i = 1; i <= 20; i++){
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    f[1] = 1;
    g[1] = 0;
    int n;
    double p;
    scanf("%d%lf", &n, &p);
    for(int i = 2; i <= n; i++){
        g[i] = 0;
        for(int j = 1; j < i; j++){
            g[i] += c[i - 1][j - 1] * f[j] * pw(1 - p, j * (i - j));
        }
        f[i] = 1 - g[i];
    }
    printf("%.7f\n", f[n]);
    return 0;
}
