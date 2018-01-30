#include <bits/stdc++.h>
using namespace std;
const int maxn = 50007;

int phi[maxn];
int f[maxn];

int main()
{
    memset(phi, 0, sizeof(phi));
    memset(f, 0, sizeof(f));
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
    for(int i = 2; i < maxn; i++){
        f[i] = f[i-1] + phi[i];
    }
    int N;
    while(~scanf("%d", &N) && N){
        printf("%d\n", 2 * f[N] + 1);
    }
    return 0;
}
