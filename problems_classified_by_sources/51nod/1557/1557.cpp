#include <bits/stdc++.h>
using namespace std;

set<int> st;

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        st.insert(x);
    }
    bool flag = true;
    while(st.size()){
        int x = *st.begin();
        if(st.count(a - x) && st.count(b - x)){
            if(st.count(a - b + x)){
                st.erase(x);
                st.erase(a - x);
                st.erase(b - x);
                st.erase(a - b + x);
                continue;
            }
            else if(st.count(b - a + x)){
                st.erase(x);
                st.erase(a - x);
                st.erase(b - x);
                st.erase(b - a + x);
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        if(st.count(a - x) && x != a - x){
            st.erase(x);
            st.erase(a - x);
            continue;
        }
        if(st.count(b - x) && x != b - x){
            st.erase(x);
            st.erase(b - x);
            continue;
        }
        if(x == a - x){
            st.erase(x);
            continue;
        }
        if(x == b - x){
            st.erase(x);
            continue;
        }
        flag = false;
        break;
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
