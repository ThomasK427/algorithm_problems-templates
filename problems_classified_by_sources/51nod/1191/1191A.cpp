//贪心思路2：从每只箭考虑（价值升序，相同时伤害降序），杀死能杀的最大的兔子

#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int D, P;
    friend bool operator<(const Node& a, const Node& b){
        if(a.P != b.P){
            return a.P < b.P;
        }
        else{
            return a.D > b.D;
        }
    }
}E[maxn];

multiset<int, greater<int> > st;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        int x;
        scanf("%d", &x);
        st.insert(x);
    }
    for(int i = 0; i < M; i++){
        scanf("%d%d", &E[i].D, &E[i].P);
    }
    sort(E, E + M);
    long long ans = 0;
    for(int i = 0; i < M; i++){
        multiset<int>::iterator it = st.lower_bound(E[i].D);
        if(it != st.end()){
            ans += E[i].P;
            st.erase(it);
            if(!st.size()){
                break;
            }
        }
    }
    if(st.size()){
        puts("No Solution");
    }
    else{
        printf("%lld\n", ans);
    }
    return 0;
}
