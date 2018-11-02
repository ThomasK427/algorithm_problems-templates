#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

struct Node{
    int t, d;
    Node(){}
    Node(int T, int D):t(T), d(D){}
};

bool operator<(const Node& a, const Node& b){
    return a.t != b.t ? a.t < b.t : a.d < b.d;
}

int main()
{
    int n, L, a;
    scanf("%d%d%d", &n, &L, &a);
    vector<Node> v;
    for(int i = 0; i < n; i++){
        int t, l;
        scanf("%d%d", &t, &l);
        v.push_back(Node(t, 1));
        v.push_back(Node(t + l, 0));
    }
    v.push_back(Node(0, 0));
    v.push_back(Node(L, 1));
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i += 2){
        int l = v[i + 1].t - v[i].t;
        ans += l / a;
    }
    printf("%d\n", ans);
    return 0;
}
