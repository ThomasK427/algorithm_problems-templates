#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

LL a[maxn];
LL s[maxn];
unordered_map<LL, int> mp;

int main()
{
    LL N;
    scanf("%lld", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", a + i);
    }
    s[0] = 0;
    int u = 0, v = 0;
    for(int i = 1; i <= N; i++){
        s[i] = (s[i - 1] + a[i]) % N;
        if(s[i] == 0){
            u = 1;
            v = i;
            break;
        }
        else if(mp.find(s[i]) != mp.end()){
            u = mp[s[i]] + 1;
            v = i;
            break;
        }
        mp[s[i]] = i;
    }
    if(u || v){
        printf("%d\n", v - u + 1);
        for(int i = u; i <= v; i++){
            printf("%lld\n", a[i]);
        }
    }
    else{
        puts("No Solution");
    }
    return 0;
}
