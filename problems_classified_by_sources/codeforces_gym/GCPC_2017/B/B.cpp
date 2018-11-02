#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long Q = 1e9 + 7;
const int maxn = 10;

int p[maxn];

LL hs(int n){
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        int t = p[(i + k) % n] - p[(j + k) % n];
        if(t == 0){
            k++;
        }else{
            if(t > 0){
                i += k + 1;
            }
            else{
                j += k + 1;
            }
            if(i == j){
                j++;
            }
            k = 0;
        }
    }
    int s = i < j ? i : j;
    LL res = 0;
    for(int r = 0; r < n; r++){
        res = res * Q + p[s];
        s = (s + 1) % n;
    }
    return res;
}

set<LL> st;

void dfs(int a, int b, int c){
    if(a == b){
        st.insert(hs(b));
    }else{
        for(int i = 1; i <= c; i++){
            p[a] = i;
            dfs(a + 1, b, c);
        }
    }
}

int cal(int c, int m){
    st.clear();
    dfs(0, m, c);
    return st.size();
}

int main()
{
    int x, y;
    while(cin >> x >> y){
        cout << cal(x, y) << endl;
    }
    return 0;
}
