#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1100000;

inline LL f(int n){
    return 1LL * n * (n + 1) / 2;
}

char str[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        int n = strlen(str);
        int d = 0;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(str[i] == '('){
                d++;
            }
            else{
                if(d > 0){
                    d--;
                    v.push_back(d);
                }
                else{
                    v.push_back(-1);
                }
            }
        }
        LL ans = 0;
        d = 0;
        stack<int> s;
        s.push(0);
        for(int i = 0; i < v.size(); i++){
            if(v[i] == -1){
                while(!s.empty()){
                    ans += f(s.top());
                    s.pop();
                }
                s.push(0);
            }
            else if(v[i] == d){
                int x = s.top();
                s.pop();
                s.push(x + 1);
            }
            else if(v[i] > d){
                while(v[i] > d){
                    s.push(0);
                    d++;
                }
                int x = s.top();
                s.pop();
                s.push(x + 1);
            }
            else{
                while(v[i] < d){
                    ans += f(s.top());
                    s.pop();
                    d--;
                }
                int x = s.top();
                s.pop();
                s.push(x + 1);
            }
        }
        while(!s.empty()){
            ans += f(s.top());
            s.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
