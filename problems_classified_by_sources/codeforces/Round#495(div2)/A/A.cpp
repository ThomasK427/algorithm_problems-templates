#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    set<int> st;
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
        st.insert(ar[i] - d);
        st.insert(ar[i] + d);
    }
    int ans = 0;
    for(auto o : st){
        int md = INF;
        for(int i = 0; i < n; i++){
            md = min(md, abs(ar[i] - o));
        }
        if(md == d){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
