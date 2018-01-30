#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Node{
    LL a, b;
    Node(){}
    Node(LL A, LL B):a(A), b(B){}
    friend bool operator<(const Node& e1, const Node& e2){
        return e1.b < e2.b;
    }
};

set<Node> st;

int main()
{
    int h, q;
    scanf("%d%d", &h, &q);
    LL a = (1LL << (h - 1)), b = (1LL << h) - 1;
    while(q--){
        int i, d, flag;
        LL l, r;
        scanf("%d%lld%lld%d", &i, &l, &r, &flag);
        d = h - i;
        LL L = (l << d), R = L - 1 + ((r - l + 1) << d);
        if(flag){
            a = max(a, L);
            b = min(b, R);
        }
        else{
            set<Node>::iterator it = st.lower_bound(Node(L, L));
            if(it == st.end()){

            }
        }
    }
    return 0;
}
