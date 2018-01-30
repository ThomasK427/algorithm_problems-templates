#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

stack<int> s;

int main()
{
    //freopen("test.txt", "r", stdin);
    char str[20];
    int n, x, cnt = 0, cur = 1;
    bool disorder = false;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; i++){
        scanf("%s", str);
        if(str[0] == 'a'){
            scanf("%d", &x);
            s.push(x);
        }
        else{
            if(s.empty()){
                cur++;
            }
            else if(s.top() != cur){
                while(!s.empty()){
                    s.pop();
                }
                cur++;
                cnt++;
            }
            else{
                s.pop();
                cur++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
