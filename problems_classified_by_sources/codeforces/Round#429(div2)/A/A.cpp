#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn];
char str[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k >> str;
    for(int i = 0; i < n; i++){
        ar[str[i] - 'a']++;
    }
    int mx = 0;
    for(int i = 0; i < 26; i++){
        mx = max(mx, ar[i]);
    }
    if(k >= mx){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
