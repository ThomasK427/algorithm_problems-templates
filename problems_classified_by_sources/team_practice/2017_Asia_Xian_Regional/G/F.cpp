#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn] = {0, 5, 5, 4, 3, 1, 2, 4, 5, 6, 7};

int f(int k){
    int ans = 0;
    for(int d = 1; d <= k; d++){
        for(int i = 1; i <= k - d + 1; i++){
            int tmp = 0;
            for(int j = i; j <= i + d - 1; j++){
                tmp ^= ar[j];
            }
            ans += tmp;
        }
    }
    return ans;
}

int main()
{
    for(int i = 1; i <= 10; i++){
        cout << i << " " << f(i) << endl;
    }
    return 0;
}
