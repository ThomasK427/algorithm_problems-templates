#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

bool isPrime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int fac(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

vector<int> g[maxn];

int main()
{
    for(int i = 2; i <= 9; i++){
        int x = fac(i), p = i;
        while(p >= 2){
            if(isPrime(p)){
                while(x % fac(p) == 0){
                    x /= fac(p);
                    g[i].push_back(p);
                }
            }
            p--;
        }
    }
    int n;
    char str[maxn];
    scanf("%d", &n);
    scanf("%s", str);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int x = str[i] - '0';
        for(int j = 0; j < g[x].size(); j++){
            ans.push_back(g[x][j]);
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
    }
    putchar('\n');
    return 0;
}
