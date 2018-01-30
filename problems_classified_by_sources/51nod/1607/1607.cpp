#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 25;

int f(int x){
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    int n = v.size(), ans = 0;
    for(int i = 0; i < n; i++){
        ans += v[i] * v[n - 1 - i];
    }
    return ans;
}

int main()
{
    int n = 34567;
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        int x = i / 1000 % 10;
        mp[x]++;
    }
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
