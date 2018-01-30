#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, k;

struct Node{
    LL st, ed, p;
    Node(){}
    Node(LL ss, LL ee, LL pp):st(ss), ed(ee), p(pp){}
    LL sum(){
        LL a = k % st;
        LL len = ed - st + 1LL;
        return len * a - len * (len - 1) / 2 * p;
    }
};

vector<Node> v;

int main()
{
    while(cin >> n >> k){
        v.clear();
        LL m = min(n, k);
        LL cur = 1;
        while(cur <= m){
            LL p = k / cur;
            v.push_back(Node(cur, min(m, k / p), p));
            cur = min(m, k / p) + 1;
        }
        LL ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans += v[i].sum();
        }
        if(n > k){
            ans += (n - k) * k;
        }
        cout << ans << endl;
    }
    return 0;
}
