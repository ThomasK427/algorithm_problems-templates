#include <cstdio>
#include <queue>
#include <set>
using namespace std;
const int maxn = 20;
const int ST = (1 << 16) - 1;
const int fx[] = {0, 0, 1, -1}, fy[] = {1, -1, 0, 0};

bool check(int x, int y){
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

struct Node{
    int S;
    int cnt;
    Node():S(0), cnt(0){}
    Node(int S_, int cnt_):S(S_), cnt(cnt_){}
};

char g[maxn][maxn];

int main()
{
    for(int i = 0; i < 4; i++){
        scanf("%s", g[i]);
    }
    int s = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            s = s * 2 + (g[i][j] == 'b' ? 0: 1);
        }
    }
    set<int> st;
    queue<Node> que;
    que.push(Node(s, 0));
    st.insert(s);
    bool flag = false;
    while(!que.empty()){
        Node nd = que.front();
        que.pop();
        if(nd.S == 0 || nd.S == ST){
            printf("%d\n", nd.cnt);
            flag = true;
            break;
        }
        for(int i = 0; i < 16; i++){
            s = nd.S;
            s ^= (1 << i);
            int u = i / 4, v = i % 4;
            for(int j = 0; j < 4; j++){
                int x = u + fx[j], y = v + fy[j];
                if(check(x, y)){
                    int k = x * 4 + y;
                    s ^= (1 << k);
                }
            }
            if(!st.count(s)){
                que.push(Node(s, nd.cnt + 1));
                st.insert(s);
            }
        }
    }
    if(!flag){
        puts("Impossible");
    }
    return 0;
}
