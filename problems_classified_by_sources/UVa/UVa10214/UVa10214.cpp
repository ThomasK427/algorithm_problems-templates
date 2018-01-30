#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2005;

int phi[maxn];

void getPhi()
{
    for(int i = 2; i < maxn; i++){
        phi[i] = 0;
    }
    phi[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(phi[i] == 0){
            for(int j = i; j < maxn; j += i){
                if(phi[j] == 0){
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    getPhi();
    LL a, b;
    while((cin >> a >> b) && a && b){
        LL ans = 0;
        for(int i = 1; i <= a; i++){
            ans += phi[i] * (b / i);
            for(int j = b / i * i + 1; j <= b; j++){
                if(__gcd(i, j) == 1)ans++;
            }
        }
        ans = ans * 4 + 4;
        printf("%.7lf\n", double(ans) / double((2 * a + 1) * (2 * b + 1) - 1));
    }
    return 0;
}
