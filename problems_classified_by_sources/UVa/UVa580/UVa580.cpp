#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;

int f[maxn], g[maxn];

//思路见《算法竞赛入门经典》p331，建表查询可以加快速度
void CreateTable()
{
    f[0] = 0;
    f[1] = 0;
    f[2] = 0;
    g[0] = 1;
    g[1] = 2;
    g[2] = 4;
    for(int i = 3; i < maxn; i++){
        f[i] = 1 << (i - 3);
        for(int j = 2; j <= i - 2; j++){
            f[i] += g[j-2] * (1 << (i - j - 2));
        }
        g[i] = (1 << i) - f[i];
    }
}

int main()
{
    CreateTable();
    int n;
    while(~scanf("%d", &n) && n){
        printf("%d\n", f[n]);
    }
    return 0;
}
