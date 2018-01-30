#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f;
const int maxn = 2005;

int ar[maxn], br[maxn], s[maxn];
set<int> st;
map<int, int> mp;

int main()
{
    //freopen("test.txt", "r", stdin);
    int k, n;
    scanf("%d%d", &k, &n);
    s[0] = 0;
    for(int i = 1; i <= k; i++){
        scanf("%d", ar + i);
        s[i] = s[i-1] + ar[i];
        st.insert(s[i]);
    }
    for(int i =1; i <= n; i++){
        scanf("%d", br + i);
    }
    set<int> ans;
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        int bg = br[1] - *it;
        mp.clear();
        for(int i = 1; i <= k; i++){
            mp[bg + s[i]]++;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(mp[br[i]] == 0){
                flag = false;
                break;
            }
            mp[br[i]]--;
        }
        if(flag){
            ans.insert(bg);
        }
    }
    printf("%d\n", int(ans.size()));
    return 0;
}
