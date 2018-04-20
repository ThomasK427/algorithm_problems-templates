#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int f(int x){
    int res = 0;
    while(x){
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}

bool check(int x){
    unordered_set<int> st;
    while(x != 1){
        st.insert(x);
        x = f(x);
        if(st.count(x)){
            return false;
        }
    }
    return true;
}

int main()
{
    int x;
    while(~scanf("%d", &x)){
        puts(check(x) ? "HAPPY" : "UNHAPPY");
    }
    return 0;
}
