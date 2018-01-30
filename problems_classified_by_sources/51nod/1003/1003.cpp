#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL N;
    cin >> N;
    LL product = 5, num = 0;
    while(product <= N){
        num++;
        product *= 5;
    }
    LL ans = 0;
    product = 5;
    for(int i = 1; i <= num; i++){
        ans += N / product;
        product *= 5;
    }
    cout << ans << endl;
    return 0;
}
