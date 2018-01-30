#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

stack<int> sp, ot;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = 0, speed = 0, idx, x;
    sp.push(INF);
    ot.push(1);
    for(int i = 0; i < n; i++){
        scanf("%d", &idx);
        if(idx == 1){
            scanf("%d", &x);
            speed = x;
            while(speed > sp.top()){
                ans++;
                sp.pop();
            }
        }
        else if(idx == 2){
            while(ot.top() == 0){
                ans++;
                ot.pop();
            }
        }
        else if(idx == 3){
            scanf("%d", &x);
            sp.push(x);
            while(speed > sp.top()){
                ans++;
                sp.pop();
            }
        }
        else if(idx == 4){
            ot.push(1);
        }
        else if(idx == 5){
            sp.push(INF);
        }
        else{
            ot.push(0);
        }
    }
    printf("%d\n", ans);
    return 0;
}

