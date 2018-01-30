#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

inline int f(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int k;
    cin >> k;
    if(k == 0){
        cout << "ab" << endl;
        return 0;
    }
    vector<int> v;
    while(k > 0){
        int x = 1;
        for(int i = 1; f(i) <= k; i++){
            x = i;
        }
        k -= f(x);
        v.push_back(x + 1);
    }
    string ans = "";
    char ch = 'a';
    for(int i = 0; i < v.size(); i++, ch++){
        for(int j = 0; j < v[i]; j++){
            ans += ch;
        }
    }
    cout << ans << endl;
    return 0;
}
