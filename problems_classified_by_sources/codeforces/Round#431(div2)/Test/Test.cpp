#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int f(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    bool flag = true;
    int mx = 0, ans = 0;
    for(int k = 1; k <= 100000; k++){
        int x = k, cnt = 0, res = 0;
        while(x > 0){
            int i;
            for(i = 1; f(i) <= x; i++);
            i--;
            x -= f(i);
            res += i + 1;
            cnt++;
        }
        mx = max(mx, cnt);
        ans = max(ans, res);
        if(cnt > 26){
            flag = false;
            break;
        }
    }
    cout << flag << endl;
    cout << mx << endl;
    cout << ans << endl;
    return 0;
}
