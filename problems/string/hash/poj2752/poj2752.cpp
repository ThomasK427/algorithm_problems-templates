#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ull;
const int maxn = 400005;
const ull Q = 233;

char s[maxn];
ull xp[maxn];
ull h[maxn];

int main()
{
    xp[0] = 1;
    for(int i = 1; i <= 400000; i++){
        xp[i] = xp[i - 1] * Q;
    }
    while(gets(s)){
        int n = strlen(s);
        h[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            h[i] = h[i + 1] * Q + ull(s[i] - 'a' + 1);
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            ull hp = h[0] - h[i] * xp[i];
            ull hs = h[n - i] - h[n] * xp[i];
            if(hp == hs){
                ans.push_back(i);
            }
        }
        for(int i = 0; i < ans.size(); i++){
            printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
        }
    }
    return 0;
}
