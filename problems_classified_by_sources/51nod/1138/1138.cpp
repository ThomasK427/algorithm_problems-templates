#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL f(LL n){
    return n * (n + 1) / 2;
}

set<LL> st;

int main()
{
    LL N;
    cin >> N;
    for(LL i = 2; f(i) <= N; i++){
        if((2 * N + i - i * i) % (2 * i) == 0){
            st.insert((2 * N + i - i * i) / (2 * i));
        }
    }
    if(st.size() == 0){
        puts("No Solution");
    }
    else{
        for(set<LL>::iterator it = st.begin(); it != st.end(); it++){
            cout << *it << endl;
        }
    }
    return 0;
}
