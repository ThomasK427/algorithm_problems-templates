#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

char str[maxn];
int mp[maxn][30];
set<char> st;

inline bool check(int idx){
    for(set<char>::iterator it = st.begin(); it != st.end(); it++){
        if(mp[idx][*it - 'a'] == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    gets(str);
    int n = strlen(str);
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            mp[i][j] = mp[i + 1][j];
        }
        mp[i][str[i] - 'a']++;
        st.insert(str[i]);
    }
    int pos = 0, cnt = st.size();
    while(cnt){
        char ch = 'z' + 1;
        int p = pos;
        for(int i = pos; check(i); i++){
            if(st.count(str[i]) && str[i] < ch){
                ch = str[i];
                p = i;
            }
        }
        putchar(ch);
        st.erase(ch);
        cnt--;
        pos = p + 1;
    }
    putchar('\n');
    return 0;
}
