#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];
int s1[maxn], s0[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    s1[0] = 0;
    s0[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        if(ar[i]){
            s1[i] = s1[i - 1] + 1;
            s0[i] = s0[i - 1];
        }
        else{
            s0[i] = s0[i - 1] + 1;
            s1[i] = s1[i - 1];
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, s0[i] + s1[n] - s1[i]);
    }
    cout << ans << endl;
    return 0;
}
