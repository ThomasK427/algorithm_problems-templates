#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

char s[maxn], t[maxn];
int mp1[30], mp2[30];

struct Node{
    char ch;
    int num;
    friend bool operator<(const Node& n1, const Node& n2){
        return n1.num > n2.num;
    }
}E[maxn];

priority_queue<Node> pq;
vector<int> idx[30];
int current[30];

int main()
{
    while(~scanf("%s%s", s, t)){
        int m = strlen(s), n = strlen(t);
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        memset(current, 0, sizeof(current));
        while(!pq.empty()){
            pq.pop();
        }
        for(int i = 0; i < 26; i++){
            idx[i].clear();
        }
        for(int i = 0; i < n; i++){
            E[i].ch = t[i];
            E[i].num = 0;
            idx[t[i] - 'a'].push_back(i);
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(s[i] == '?'){
                cnt++;
            }
            else{
                int p = s[i] - 'a';
                if(idx[p].empty()){
                    continue;
                }
                E[idx[p][current[p]]].num++;
                current[p] = (current[p] + 1) % int(idx[p].size());
            }
        }
        for(int i = 0; i < n; i++){
            pq.push(E[i]);
        }
        string ans = "";
        while(cnt--){
            Node e = pq.top();
            pq.pop();
            ans += e.ch;
            e.num++;
            pq.push(e);
        }
        int p = 0;
        for(int i = 0; i < m; i++){
            if(s[i] == '?'){
                putchar(ans[p++]);
            }
            else{
                putchar(s[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
