#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 1005;

struct Node{
    LL u, v;
    Node(){}
    Node(LL uu, LL vv):u(uu), v(vv){}
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL a, b, x, y;
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        unordered_set<LL> st;
        queue<Node> que;
        que.push(Node(a, b));
        while(!que.empty()){
            Node nd = que.front();
            que.pop();
            LL p = nd.u, q = nd.v;
            st.insert(p * Q + q);
            if(p * q){
                if(p > q){
                    que.push(Node(p % q, q));
                }
                else if(p < q){
                    que.push(Node(q, p % q));
                }
                else{
                    que.push(Node(p, 0));
                    que.push(Node(0, p));
                }
            }
        }
        bool flag = false;
        while(!que.empty()){
            que.pop();
        }
        que.push(Node(x, y));
        while(!que.empty()){
            Node nd = que.front();
            que.pop();
            LL p = nd.u, q = nd.v;
            if(st.count(p * Q + q)){
                flag = true;
                break;
            }
            if(p * q){
                if(p > q){
                    que.push(Node(p % q, q));
                }
                else if(p < q){
                    que.push(Node(q, p % q));
                }
                else{
                    que.push(Node(p, 0));
                    que.push(Node(0, p));
                }
            }
        }
        if(flag){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}
