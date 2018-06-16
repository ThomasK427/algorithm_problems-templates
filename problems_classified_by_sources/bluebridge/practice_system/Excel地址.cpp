#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 26;

int main()
{
    LL n;
    cin >> n;
    string ans = "";
    while(n){
        LL a = n / Q, b = n % Q;
        if(b == 0){
            ans += "Z";
            a--;
        }
        else{
            ans += ('A' + b - 1);
        }
        n = max(a, 0LL);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
