/**
*codeforces 888E
*折半枚举(双向搜索)
*将数组分成均等的两部分，在两部分分别深搜枚举答案
*再将两部分的答案组合起来
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50;

LL ar[maxn];
LL ans = 0;
LL m;
int n;

set<LL, greater<LL> > st;

void dfs1(int k, LL cur){
    if(k >= n / 2){
        st.insert(cur);
        return;
    }
    dfs1(k + 1, cur);
    dfs1(k + 1, (cur + ar[k]) % m);
}

void dfs2(int k, int cur){
    if(k >= n){
        LL x = m - 1 - cur;
        set<LL>::iterator it = st.lower_bound(x);
        if(it == st.end()){
            ans = max(ans, x);
        }
        else{
            ans = max(ans, cur + *it);
        }
        return;
    }
    dfs2(k + 1, cur);
    dfs2(k + 1, (cur + ar[k]) % m);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        ar[i] %= m;
    }
    dfs1(0, 0LL);
    dfs2(n / 2, 0LL);
    cout << ans << endl;
    return 0;
}
