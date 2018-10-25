#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

LL lcm(LL a, LL b){
    return a / __gcd(a, b) * b;
}

int main()
{
    LL b, ans = 0;
    cin >> b;
    for(LL i = 1; i * i <= b; i++){
        if(b % i == 0){
            ans++;
            LL j = b / i;
            if(i != j){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
