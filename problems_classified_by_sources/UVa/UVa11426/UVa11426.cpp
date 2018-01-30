#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 4000005;

int phi[maxn];
LL f[maxn], s[maxn];

void getPhi()
{
    for(int i = 2; i < maxn; i++){
        phi[i] = 0;
    }
    phi[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!phi[i]){
            for(int j = i; j < maxn; j += i){
                if(!phi[j]){
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void getF()
{
    getPhi();
    for(int i = 1; i < maxn; i++){
        for(int j = i * 2; j < maxn; j += i){
            f[j] += i * phi[j / i];
        }
    }
}

void getS()
{
    getF();
    s[1] = 0;
    for(int i = 2; i < maxn; i++){
        s[i] = s[i - 1] + f[i];
    }
}

int main()
{
    getS();
    int n;
    while(~scanf("%d", &n) && n){
        printf("%lld\n", s[n]);
    }
    return 0;
}
