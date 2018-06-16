#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull base = 233;
const int maxn = 40005;

char s[maxn];
ull h[maxn], xp[maxn];
int m, n;

int check(int k){
    unordered_map<ull, int> mp;
    int ans = -1;
    for(int i = 0; i <= n - k; i++){
        int hs = h[i] - h[i + k] * xp[k];
        mp[hs]++;
        if(mp[hs] >= m){
            ans = i;
        }
    }
    return ans;
}

int main()
{
    xp[0] = 1;
    for(int i = 1; i <= 40000; i++){
        xp[i] = xp[i - 1] * base;
    }
    while(~scanf("%d", &m) && m){
        scanf("%s", s);
        n = strlen(s);
        h[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            h[i] = h[i + 1] * base + (s[i] - 'a' + 1);
        }
        int low = 0, high = n, ans = 0;
        while(low < high){
            int mid = low + high + 1 >> 1;
            int tmp = check(mid);
            if(tmp != -1){
                low = mid;
                ans = tmp;
            }
            else{
                high = mid - 1;
            }
        }
        if(low){
            printf("%d %d\n", low, ans);
        }
        else{
            puts("none");
        }
    }
    return 0;
}
