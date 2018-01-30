#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

bool rem[maxn];
int ar[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    n *= 2;
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
    }
    sort(ar + 1, ar + n + 1);
    int ans = INF;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            memset(rem, false, sizeof(rem));
            rem[i] = true;
            rem[j] = true;
            vector<int> v;
            for(int k = 1; k <= n; k++){
                if(!rem[k]){
                    v.push_back(ar[k]);
                }
            }
            int res = 0;
            for(int k = 0; k < v.size(); k += 2){
                res += abs(v[k] - v[k + 1]);
            }
            ans = min(ans, res);
        }
    }
    printf("%d\n", ans);
    return 0;
}
