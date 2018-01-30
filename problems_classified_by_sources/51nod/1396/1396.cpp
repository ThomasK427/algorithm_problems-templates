#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

char str[maxn];
int s0[maxn], s1[maxn];
int n;

inline int f1(int k){
    if(k >= 0){
        return s0[k] - s0[0];
    }
    else{
        return 0;
    }
}

inline int f2(int k){
    if(k < n){
        return s1[n] - s1[k];
    }
    else{
        return 0;
    }
}

int main()
{
    scanf("%s", str + 1);
    n = strlen(str + 1);
    s0[0] = 0;
    s1[0] = 0;
    for(int i = 1; i <= n; i++){
        s0[i] = s0[i - 1] + 1 - (str[i] - '0');
        s1[i] = s1[i - 1] + str[i] - '0';
    }
    bool flag = false;
    for(int i = 0; i <= n; i++){
        if(f1(i) == f2(i)){
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        puts("-1");
    }
    return 0;
}
