#include <cstdio>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int maxn = 20;
const int maxm = 1000005;

struct Node{
    int S, idx;
    Node():S(0), idx(-1){}
    Node(int S_, int idx_):S(S_), idx(idx_){}
};

int row[maxm], col[maxm], last[maxm];
int st[1 << 17];

char g[maxn][maxn];

int main()
{
    for(int i = 0; i < 4; i++){
        scanf("%s", g[i]);
    }
    int s = 0;
    for(int i = 3; i >= 0; i--){
        for(int j = 3; j >= 0; j--){
            s = s * 2 + (g[i][j] == '-' ? 0 : 1);
        }
    }
    queue<Node> que;
    que.push(Node(s, -1));
    st[s] = 1;
    int p = -1, idx = 0;
    while(!que.empty()){
        Node nd = que.front();
        que.pop();
        if(nd.S == 0){
            p = nd.idx;
            break;
        }
        for(int i = 0; i < 16; i++){
            int u = i / 4, v = i % 4;
            s = nd.S;
            s ^= (1 << i);
            for(int j = 0; j < 4; j++){
                int p = u * 4 + j, q = j * 4 + v;
                s ^= (1 << p);
                s ^= (1 << q);
            }
            if(st[s] == 0){
                row[idx] = u + 1;
                col[idx] = v + 1;
                last[idx] = nd.idx;
                que.push(Node(s, idx++));
                st[s] = 1;
                if(s == 0){
                    p = idx - 1;
                    goto HERE;
                }
            }
        }
    }
    HERE:;
    stack<int> sk;
    while(p >= 0){
        sk.push(p);
        p = last[p];
    }
    printf("%d\n", int(sk.size()));
    while(!sk.empty()){
        p = sk.top();
        sk.pop();
        printf("%d %d\n", row[p], col[p]);
    }
    return 0;
}
