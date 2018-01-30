#include <bits/stdc++.h>
using namespace std;

long long f(int a, int n){
    long long res = 0;
    for(int i = 0; i < n; i++){
        res = res * 10 + a;
    }
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("WA.txt", "w", stdout);
    int a, b, d, n;
    while(cin >> a >> n >> b){
        cout << f(a, n) << endl;
        cout << f(a, n) * b << endl;
        map<int, int> mp;
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
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
            cout << it->first << "\t" << it->second << endl;
        }
    }
    return 0;
}
