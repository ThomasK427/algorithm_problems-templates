#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    if((n & 1) && (ar[1] & 1) && (ar[n] & 1)){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
