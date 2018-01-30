#include <bits/stdc++.h>
using namespace std;

char g[10][5];
char str[10];
int top[10];

inline int f(int n){
    return n * (n - 1) / 2;
}

inline int Hash(){
    int p = 1, sum = 0;
    for(int i = 0; i < 9; i++){
        sum += p * top[i];
        p *= 5;
    }
    return sum;
}

unordered_map<int, double> dp;

double dfs(){
    if(dp.count(Hash())){
        return dp[Hash()];
    }
    bool flag = true;
    for(int i = 0; i < 9; i++){
        if(top[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        dp[Hash()] = 1.0;
        return 1.0;
    }
    map<char, int> mp;
    for(int i = 0; i < 9; i++){
        if(top[i]){
            mp[g[i][top[i]]]++;
        }
    }
    int sum = 0;
    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
        sum += f(it->second);
    }
    if(sum == 0){
        dp[Hash()] = 0.0;
        return 0.0;
    }
    double e = 1.0 / sum, res = 0.0;
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(top[i] >= 1 && top[j] >= 1 && g[i][top[i]] == g[j][top[j]]){
                top[i]--;
                top[j]--;
                res += dfs() * e;
                top[i]++;
                top[j]++;
            }
        }
    }
    dp[Hash()] = res;
    return res;
}

int main()
{
    while(~scanf("%s", str)){
        dp.clear();
        g[0][1] = str[0];
        for(int i = 2; i <= 4; i++){
            scanf("%s", str);
            g[0][i] = str[0];
        }
        for(int i = 1; i < 9; i++){
            for(int j = 1; j <= 4; j++){
                scanf("%s", str);
                g[i][j] = str[0];
            }
        }
        for(int i = 0; i < 9; i++){
            top[i] = 4;
        }
        printf("%.6f\n", dfs());
    }
    return 0;
}
