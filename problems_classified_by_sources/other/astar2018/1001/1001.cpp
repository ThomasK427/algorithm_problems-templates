#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1050;

int ar[maxn];
char str[maxn];
int used[maxn];
int n, m, k;

int resolve(){
    int res = 0;
    for(int i = 0; i < m; i++){
        res = res * 2 + (str[i] - 'A');
    }
    return res;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            ar[i] = resolve();
        }
        memset(used, 0, sizeof(used));
        for(int S = 1; S < (1 << m); S++){
            if(used[S]){
                continue;
            }
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++){
                mp[S & ar[i]]++;
            }
            LL sum = 0, square_sum = 0;
            for(auto o : mp){
                sum += o.second;
                square_sum += o.second * o.second;
            }
            LL cnt = (sum * sum - square_sum) / 2;
            if(cnt >= k){
                for(int V = S; V < (1 << m); V++){
                    if((V & S) == S){
                        used[V] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < (1 << m); i++){
            ans += used[i];
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
