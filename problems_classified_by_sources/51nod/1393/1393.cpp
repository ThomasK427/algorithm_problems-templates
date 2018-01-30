#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

char str[maxn];
unordered_map<int, int> mp;

int main()
{
    scanf("%s", str + 1);
    int sum = 0, len = strlen(str + 1), ans = 0;
    mp[0] = 0;
    for(int i = 1; i <= len; i++){
        sum += str[i] - '0';
        if(mp.count(i - 2 * sum)){
            ans = max(ans, i - mp[i - 2 * sum]);
        }
        else{
            mp[i - 2 * sum] = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
