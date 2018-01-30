#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL> > que;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        LL x;
        scanf("%lld", &x);
        que.push(x);
    }
    LL ans = 0;
    if(que.size() % 2 == 0){
        LL x = que.top();
        que.pop();
        LL y = que.top();
        que.pop();
        ans += x + y;
        que.push(x + y);
    }
    while(que.size() >= 3){
        LL x = que.top();
        que.pop();
        LL y = que.top();
        que.pop();
        LL z = que.top();
        que.pop();
        ans += x + y + z;
        que.push(x + y + z);
    }
    printf("%lld\n", ans);
    return 0;
}
