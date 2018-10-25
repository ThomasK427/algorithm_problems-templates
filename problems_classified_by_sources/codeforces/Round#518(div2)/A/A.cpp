#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

int main()
{
    LL N, M, K, L;
    cin >> N >> M >> K >> L;
    LL a = (L + K + M - 1) / M;
    LL b = N / M;
    if(a <= b){
        cout << a << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
