#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > que;

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    int n, w, x, y;
    n = read();
    for(int i = 0; i < n; i++){
        w = read();
        que.push(w);
    }
    int ans = 0;
    while(que.size() >= 2){
        x = que.top();
        que.pop();
        y = que.top();
        que.pop();
        if(x == y){
            que.push(x + 1);
        }
        else{
            ans++;
            que.push(y);
        }
    }
    ans++;
    printf("%d\n", ans);
    return 0;
}
