#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1010;

ULL f[maxn * maxn];
ULL n;
ULL a, b;

int qpow(ULL a, ULL b, ULL m){
    ULL base = a, res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * base) % m;
        }
        b >>= 1;
        base = (base * base) % m;
    }
    return int(res);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    int T;
    cin >> T;
    while(T--){
        cin >> a >> b >> n;
        if(n == 1 || a == 0){
            cout << "0" << endl;
            continue;
        }
        int M = 2;
        for(int i = 3; i <= n * n + n + 10; i++){
            f[i] = (f[i-1] + f[i-2]) % n;
            if(f[i] == f[1] && f[i-1] == f[0]){
                M = i - 1;
                break;
            }
        }
        cout << f[qpow(a % M, b, M)] << endl;
    }
    return 0;
}
