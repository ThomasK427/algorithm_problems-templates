#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1000005;

int par[maxn], val[maxn];

struct Node{
    int p, v;
    Node():p(0), v(0){}
};

Node Find(int x){
    if(x == par[x]){
        Node node;
        node.p = x;
        node.v = 0;
        return node;
    }
    else{
        Node node = Find(par[x]);
        node.v += val[x];
        par[x] = node.p;
        val[x] = node.v;
        return node;
    }
}

void Unite(int a, int b, int w){
    Node node_a = Find(a), node_b = Find(b);
    par[node_b.p] = node_a.p;
    val[node_b.p] = w + val[a] - val[b];
}

Node check(int a, int b){
    Node node_a = Find(a), node_b = Find(b);
    if(node_a.p == node_b.p){
        Node node;
        node.p = 1;
        node.v = node_b.v - node_a.v;
        return node;
    }
    else{
        Node node;
        node.p = 0;
        return node;
    }
}

int main()
{
    int N, M;
    while(~scanf("%d%d", &N, &M) && (N || M)){
        for(int i = 0; i <= N; i++){
            par[i] = i;
        }
        memset(val, 0, sizeof(val));
        while(M--){
            char ch;
            int a, b, w;
            getchar();
            scanf("%c", &ch);
            if(ch == '!'){
                scanf("%d%d%d", &a, &b, &w);
                Unite(a, b, w);
            }
            else{
                scanf("%d%d", &a, &b);
                Node node = check(a, b);
                if(node.p){
                    printf("%d\n", node.v);
                }
                else{
                    puts("UNKNOWN");
                }
            }
        }
    }
    return 0;
}
