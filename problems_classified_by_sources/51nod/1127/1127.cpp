#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

char str[maxn];

struct ST{
    map<char, int> mp;
    int cnt;
    ST(){
        mp.clear();
        cnt = 0;
    }
    void Insert(char c){
        mp[c]++;
        if(mp[c] == 1){
            cnt++;
        }
    }
    void Remove(char c){
        mp[c]--;
        if(mp[c] == 0){
            cnt--;
        }
    }
    bool check(){
        return cnt >= 26;
    }
}st;

int main()
{
    scanf("%s", str);
    int i = 0, j = 0, n = strlen(str), ans = n + 1;
    while(true){
        while(j < n && !st.check()){
            st.Insert(str[j++]);
        }
        if(!st.check()){
            break;
        }
        ans = min(ans, j - i);
        st.Remove(str[i++]);
    }
    if(ans == n + 1){
        puts("No Solution");
    }
    else{
        printf("%d\n", ans);
    }
    return 0;
}

