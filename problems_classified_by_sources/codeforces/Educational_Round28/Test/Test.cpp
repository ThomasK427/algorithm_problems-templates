#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
int val[50];
int k;
int solve(int n, int M) {
    int ans = 0;
    for(int i = 0; i < k; ++ i) {
        if(M >= n * val[i]) {
            M -= n * val[i];
            ans += n;
        } else {
            ans += M / val[i];
            M = 0;
            break;
        }
    }
    return ans;
}
int main() {
    int n, M;
    scanf("%d%d%d", &n, &k, &M);
    int sum = 0;
    for(int i = 0; i < k; ++ i)
        scanf("%d", val + i), sum += val[i];
    sort(val, val + k);
    int ans = 0;
    for(int i = 0; i <= n; ++ i) {
        if(M < i * sum) break;
        ans = max(ans, i * (k + 1) + solve(n - i, M - i * sum));
    }
    cout << ans << endl;
}
