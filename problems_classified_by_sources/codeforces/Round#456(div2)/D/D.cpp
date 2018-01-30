#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

LL f(LL n, LL m, LL r, LL p, LL q){
    return (min(p, n - r + 1) - max(1LL, p - r + 1) + 1) * (min(q, m - r + 1) - max(1LL, q - r + 1) + 1);
}

int main()
{
    int n = 8, m = 10, r = 6;
    map<LL, LL> mp, mmp;
    for(LL i = 1; i <= n; i++){
        for(LL j = 1; j <= m; j++){
            cout << f(n, m, r, i, j) << "\t";
            mmp[f(n, m, r, i, j)]++;
        }
        cout << endl;
    }
    if(n > m){
        swap(n, m);
    }
    if(2 * r <= n){
        for(LL i = 1; i <= r; i++){
            for(LL j = 1; j <= r; j++){
                mp[f(n, m, r, i, j)] += 4;
            }
        }
        mp[r * r] += (m - 2 * r) * (n - 2 * r);
        for(LL i = 1; i <= r; i++){
            mp[i * r] += (m + n - 4 * r) * 2;
        }
    }
    else{

    }
    for(auto o : mmp){
        //cout << o.first << " " << o.second << " " << mp[o.first] << endl;
    }
    return 0;
}
