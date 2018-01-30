#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

char str[maxn];
unordered_map<char, int> mp;

void init(){
    for(int i = 0; i < 10; i++){
        mp[i + '0'] = i;
    }
    for(char ch = 'A'; ch <= 'Z'; ch++){
        mp[ch] = ch - 'A' + 10;
    }
}

int main()
{
    init();
    scanf("%s", str);
    int K = 0, n = strlen(str);
    for(int i = 0; i < n; i++){
        K = max(K, mp[str[i]] + 1);
    }
    bool flag = false;
    while(K <= 36){
        int res = 0;
        for(int i = 0; i < n; i++){
            res = ((res * K) % (K - 1) + mp[str[i]] % (K - 1)) % (K - 1);
        }
        if(res == 0){
            printf("%d\n", K);
            flag = true;
            break;
        }
        K++;
    }
    if(!flag){
        puts("No Solution");
    }
    return 0;
}
