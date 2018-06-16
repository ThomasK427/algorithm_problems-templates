#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int n = strlen(s);
        map<char, int> mp1, mp2;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                mp1[s[i]]++;
            }
            else{
                mp2[s[i]]++;
            }
        }
        int c1 = 0, c2 = 0;
        for(map<char, int>::iterator it = mp1.begin(); it != mp1.end(); it++){
            c1 = max(c1, it->second);
        }
        for(map<char, int>::iterator it = mp2.begin(); it != mp2.end(); it++){
            c2 = max(c2, it->second);
        }
        int ans = n - c1 - c2;
        printf("%d\n", ans);
    }
    return 0;
}
