#include <bits/stdc++.h>
using namespace std;

bool check(int x){
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    vector<int> u;
    for(int i = 0; i + 1 < v.size(); i++){
        u.push_back(v[i + 1] - v[i]);
    }
    int state = 0;
    for(int i = 0; i < u.size(); i++){
        if(state == 0){
            if(u[i] < 0){
                state = 1;
            }
            else{
                return false;
            }
        }
        else if(state == 1){
            if(u[i] > 0){
                state = 2;
            }
            else if(u[i] == 0){
                return false;
            }
        }
        else if(state == 2){
            if(u[i] <= 0){
                return false;
            }
        }
    }
    return state == 2;
}

int main()
{
    int ans = 0;
    for(int i = 100; i <= 100000; i++){
        if(check(i)){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
