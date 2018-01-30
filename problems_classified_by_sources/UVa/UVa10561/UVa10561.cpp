#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

char str[maxn];
int g[maxn];
int n;

void init(){
    g[0] = 0;
    g[1] = 1;
    g[2] = 1;
    g[3] = 1;
    for(int i = 4; i <= 200; i++){
        unordered_set<int> st;
        for(int j = 3; j <= 5 && i - j >= 0; j++){
            st.insert(g[i - j]);
        }
        for(int j = 1; i - 5 - j >= j; j++){
            st.insert(g[j] ^ g[i - 5 - j]);
        }
        for(int j = 0; ; j++){
            if(!st.count(j)){
                g[i] = j;
                break;
            }
        }
    }
}

bool judge(){
    for(int i = 0; i + 2 < n; i++){
        if(str[i] == 'X' && str[i + 1] == 'X' && str[i + 2] == 'X'){
            return true;
        }
    }
    for(int i = 0; i < n; i++){
        if(i + 1 < n && str[i] == 'X' && str[i + 1] == 'X'){
            return true;
        }
        if(i + 2 < n && str[i] == 'X' && str[i + 2] == 'X'){
            return true;
        }
    }
    int p1 = -1, p2 = -1;
    for(int i = 0; i < n; i++){
        if(str[i] == 'X'){
            p1 = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(str[i] == 'X'){
            p2 = i;
            break;
        }
    }
    int nim = 0;
    int f1 = 0, f2 = 2;
    for(int i = 0; i < n; i++){
        if(i >= p1){
            f1 = 2;
        }
        if(i > p2){
            f2 = 0;
        }
        if(str[i] == 'X'){
            continue;
        }
        int j = i;
        while(j < n && str[j] == '.'){
            j++;
        }
        if(j - i - f1 - f2 >= 0){
            nim ^= g[j - i - f1 - f2];
        }
    }
    return nim == 0;
}

bool check(int x){
    if(str[x] == 'X'){
        return false;
    }
    str[x] = 'X';
    bool ans = judge();
    str[x] = '.';
    return ans;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        n = strlen(str);
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(check(i)){
                v.push_back(i);
            }
        }
        if(v.size() == 0){
            puts("LOSING\n");
        }
        else{
            puts("WINNING");
            for(int i = 0; i < v.size(); i++){
                printf("%d%c", v[i], i + 1 == v.size() ? '\n' : ' ');
            }
        }
    }
    return 0;
}
