#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f;
const int maxn = 1005;

char a[maxn], b[maxn];
map<char, char> mp;
char str[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    cin >> a >> b;
    for(int i = 0; i < 26; i++){
        mp[a[i]] = b[i];
    }
    cin >> str;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(islower(str[i])){
            str[i] = mp[str[i]];
        }
        else if(isupper(str[i])){
            str[i] = toupper(mp[tolower(str[i])]);
        }
    }
    cout << str << endl;
    return 0;
}
