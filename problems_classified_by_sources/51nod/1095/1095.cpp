#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<string, int> mp1, mp2;

int main()
{
    string str;
    int N, Q;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        mp1[str]++;
        sort(str.begin(), str.end());
        mp2[str]++;
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> str;
        int a = mp1[str];
        sort(str.begin(), str.end());
        int b = mp2[str];
        cout << b - a << endl;
    }
    return 0;
}
