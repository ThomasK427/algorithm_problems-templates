#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

char s[maxn], t[maxn];
set<char> st;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for(int i = 0; i < n; i++){
        st.insert(s[i]);
    }
    t[k] = '\0';
    char minchar = *st.begin(), maxchar = *st.rbegin();
    if(k > n){
        for(int i = 0; i < n; i++){
            t[i] = s[i];
        }
        for(int i = n; i < k; i++){
            t[i] = minchar;
        }
    }
    else{
        int p = k - 1;
        while(p >= 0){
            if(s[p] == maxchar){
                t[p] = minchar;
                p--;
            }
            else{
                set<char>::iterator iter = st.find(s[p]);
                ++iter;
                t[p] = *iter;
                p--;
                break;
            }
        }
        while(p >= 0){
            t[p] = s[p];
            p--;
        }
    }
    puts(t);
    return 0;
}
