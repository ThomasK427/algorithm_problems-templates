#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while(x % 10 == 0){
        x /= 10;
    }
    vector<int> u, v;
    while(x){
        u.push_back(x % 10);
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    bool flag = true;
    for(int i = 0; i < u.size(); i++){
        if(u[i] != v[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
