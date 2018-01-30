#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(int a, int n){
    LL res = 0;
    for(int i = 0; i < n; i++){
        res = res * 10 + a;
    }
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("WA.txt", "w", stdout);
    int T;
    cin >> T;
    int a, b, d, n;
    while(T--){
        map<int, int> mp;
        cin >> a >> b >> d >> n;
        if(n < 10){
            LL x = f(a, n) * b;
            while(x){
                mp[x % 10]++;
                x /= 10;
            }
            cout << mp[d] << endl;
            continue;
        }
        if(a * b < 10){
            mp[a * b] = n;
        }
        else{
            int sum = n + 1, u = a * b / 10, v = a * b % 10;
            mp[v]++;
            sum--;
            if(u + v >= 10){
                mp[(u + v) % 10]++;
                sum--;
                mp[u + (u + v) / 10]++;
                sum--;
                mp[(u + v) / 10 + (u + v) % 10] += sum;
            }
            else{
                mp[u]++;
                sum--;
                mp[u + v] += sum;
            }
        }
        cout << mp[d] << endl;
    }
    return 0;
}
