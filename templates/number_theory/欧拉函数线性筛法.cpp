#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 70005;

int phi[maxn], prime[maxn];
int tot;

void getEuler(int n){
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    tot = 0;
    for(int i = 2; i <= n; i++){
        if(phi[i] == 0){
            phi[i] = i - 1;
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            if(i % prime[j]){
                phi[i * prime[j]] = (prime[j] - 1) * phi[i];
            }
            else{
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }
}


int main()  //POJ1284
{
    getEuler(70000);
    int n;
    while(~scanf("%d", &n)){
        printf("%d\n", phi[n - 1]);
    }
    return 0;
}
