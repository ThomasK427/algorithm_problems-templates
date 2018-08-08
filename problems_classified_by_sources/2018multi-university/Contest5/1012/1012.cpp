#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int extdig(int x, int n){
    for(int i = 0; i < n; i++){
        x /= 10;
    }
    return x % 10;
}

int cnt(int x){
    int c = 0;
    while(x > 0){
        x /= 10;
        c++;
    }
    return c;
}

int swp(int x, int i, int j){
    int xi = extdig(x, i), xj = extdig(x, j);
    int xp = 1;
    for(int k = 0; k <= max(i, j); k++){
        if(k == i){
            x = x + xp * xj - xp * xi;
        }else if(k == j){
            x = x + xp * xi - xp * xj;
        }
        xp *= 10;
    }
    return x;
}

struct Node{
    int x, d;
    Node(){}
    Node(int xx, int dd): x(xx), d(dd){}
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d%d", &n, &k);
        if(n == 1000000000){
            puts("1000000000 1000000000");
            continue;
        }
        int m = cnt(n);
        queue<Node> que;
        que.push(Node(n, 0));
        unordered_map<int, int> mp;
        mp[n] = 0;
        k = min(k, 8);
        int max_ans = n, min_ans = n;
        while(!que.empty()){
            Node nd = que.front();
            que.pop();
            for(int i = 0; i < m; i++){
                for(int j = i + 1; j < m; j++){
                    int y = swp(nd.x, i, j);
                    if(mp.find(y) == mp.end()){
                        if(nd.d + 1 <= k){
                            max_ans = max(max_ans, y);
                            min_ans = min(min_ans, y);
                        }
                        if(nd.d + 1 <= k - 1){
                            que.push(Node(y, nd.d + 1));
                            mp[y] = nd.d + 1;
                        }
                    }
                }
            }
        }
        printf("%d %d\n", min_ans, max_ans);
    }
    return 0;
}
