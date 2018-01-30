#include <bits/stdc++.h>
using namespace std;

set<int> st;
set<int> used;

int main()
{
    int K, N;
    scanf("%d%d", &K, &N);
    for(int i = 0; i < N; i++){
        int x;
        scanf("%d", &x);
        st.insert(x);
    }
    bool flag = false;
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        if((used.find(*it) == used.end()) && (*it != K - *it) && (st.find(K - *it) != st.end())){
            cout << *it << " " << K - *it << endl;
            used.insert(*it);
            used.insert(K - *it);
            flag = true;
        }
        else{
            used.insert(*it);
        }
    }
    if(!flag){
        puts("No Solution");
    }
    return 0;
}
