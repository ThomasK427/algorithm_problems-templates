#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int ar[maxn];

int f[maxn];

int s[maxn];

int main()
{
    memset(ar, 0, sizeof(ar));
    int a = 1, b = 1, c;
    for(int i = 0; i < 15; i++){
        ar[b] = 1;
        c = a + b;
        b = a;
        a = c;
    }
    s[0] = 0;
    map<int, int> mp;
    for(int i = 1; i <= 1000; i++){
        if(ar[i]){
            f[i] = 1;
        }
        else{
            int mi = INF;
            for(int j = 1; j <= i - j; j++){
                mi = min(mi, f[j] + f[i - j]);
            }
            f[i] = mi;
        }
        s[i] = s[i - 1] + f[i];
        if(!mp.count(f[i])){
            mp[f[i]] = i;
        }
        cout << f[i] << "\t" << i << "\t" << s[i] << "\t" << s[i] - i << endl;
    }
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << "\t" << it->second + 1 << endl;
    }
    return 0;
}
