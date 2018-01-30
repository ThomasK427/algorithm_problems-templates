#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k, M, sum = 0;
    scanf("%d%d%d", &n, &k, &M);
    for(int i = 0; i < k; i++){
        scanf("%d", ar + i);
        sum += ar[i];
    }
    sort(ar, ar + k);
    int mx = min(n, M / sum);
    int ans = 0;
    for(int r = 0; r <= mx; r++){
        int res = r * k + r, m = M;
        m -= r * sum;
        for(int i = 0; i < k - 1; i++){
            for(int j = 0; j < n - r; j++){
                if(ar[i] <= m){
                    m -= ar[i];
                    res++;
                }
                else{
                    m = -1;
                    break;
                }
            }
            if(m == -1){
                break;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
