#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

LL a[maxn];
map<LL, int> mp;

LL gcd(LL a, LL b)
{
    if(b == 0)return a;
    else return gcd(b, a % b);
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--){
        mp.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", a + i);
        }
        LL ans = a[1];
        mp[a[1]] = 1;
        for(int i = 2; i <= n; i++){
            for(map<LL, int>::iterator it = mp.begin(); it != mp.end(); it++){
                LL GCD = it->first;
                int idx = it->second;
                LL newGCD = gcd(GCD, a[i]);
                if(mp[newGCD] == 0){
                    mp[newGCD] = idx;
                }
                else{
                    mp[newGCD] = min(mp[newGCD], idx);
                }
                if(newGCD != GCD){
                    mp[GCD] = 0;
                }
            }
            if(mp[a[i]] == 0){
                mp[a[i]] = i;
            }
            queue<LL> waste;
            for(map<LL, int>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second == 0){
                    waste.push(it->first);
                }
            }
            while(!waste.empty()){
                mp.erase(waste.front());
                waste.pop();
            }
            for(map<LL, int>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second != 0){
                    ans = max(ans, (i - it->second + 1) * it->first);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
