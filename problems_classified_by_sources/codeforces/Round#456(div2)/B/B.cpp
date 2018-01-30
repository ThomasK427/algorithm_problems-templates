#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

LL f(LL x){
    LL y = 0;
    while(y < x){
        y = y * 2 + 1;
    }
    return y;
}

int main()
{
    LL n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n << endl;
    }
    else{
        cout << f(n) << endl;
    }
    return 0;
}
