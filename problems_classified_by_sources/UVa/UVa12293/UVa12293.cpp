#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e9;

unordered_set<LL> st;

void init(){
    LL x = 1;
    while(x <= INF){
        st.insert(x);
        x = x * 2 + 1;
    }
}

int main()
{
    init();
    LL n;
    while(~scanf("%lld", &n) && n){
        if(st.count(n)){
            puts("Bob");
        }
        else{
            puts("Alice");
        }
    }
    return 0;
}
