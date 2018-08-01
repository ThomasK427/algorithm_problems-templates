#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

int a[maxn];
int n;

bool dfs(int x){
    if(a[x] > 0){
        return false;
    }
    for(int i = 1; i <= x; i++){
        if(x % i == 0){
            a[i]++;
        }
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(dfs(i)){
            flag = false;
            break;
        }
    }
    for(int i = 1; i <= x; i++){
        if(x % i == 0){
            a[i]--;
        }
    }
    return flag;
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(dfs(i)){
            return true;
        }
    }
    return false;
}

int main()
{
    for(int i = 1; i <= 10; i++){
        memset(a, 0, sizeof(a));
        n = i;
        printf("%d %d\n", i, int(check()));
    }
    return 0;
}
