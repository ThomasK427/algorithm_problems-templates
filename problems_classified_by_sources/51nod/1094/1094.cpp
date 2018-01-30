#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

LL s[maxn];
map<LL, int> mp;

struct Node{
    int a, b;
    Node(){}
    Node(int A, int B):a(A), b(B){}
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.a != e2.a){
            return e1.a < e2.a;
        }
        else{
            return e1.b < e2.b;
        }
    }
};

vector<Node> ans;

int main()
{
    //freopen("test.txt", "r", stdin);
    int N;
    LL K;
    scanf("%d%lld", &N, &K);
    mp[0] = 0;
    s[0] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%lld", s + i);
        s[i] += s[i - 1];
        if(mp.find(s[i] - K) != mp.end()){
            ans.push_back(Node(mp[s[i] - K] + 1, i));
        }
        else if(mp.find(s[i]) == mp.end()){
            mp[s[i]] = i;
        }
    }
    if(ans.size() == 0){
        puts("No Solution");
    }
    else{
        sort(ans.begin(), ans.end());
        printf("%d %d\n", ans[0].a, ans[0].b);
    }
    return 0;
}

