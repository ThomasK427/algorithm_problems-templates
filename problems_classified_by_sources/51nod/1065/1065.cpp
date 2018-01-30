#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 50005;

set<LL> st;

int main()
{
    int N;
    LL x, sum = 0, ans = inf;
    st.insert(sum);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &x);
        sum += x;
        set<LL>::iterator it = st.lower_bound(sum);
        if(it == st.end()){
            it--;
        }
        bool flag = true;
        while(*it >= sum){
            if(it == st.begin()){
                flag = false;
                break;
            }
            else{
                it--;
            }
        }
        if(flag){
            ans = min(ans, sum - *it);
        }
        st.insert(sum);
    }
    printf("%d\n", ans);
    return 0;
}
