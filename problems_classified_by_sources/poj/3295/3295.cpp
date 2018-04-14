#include <cstdio>
#include <map>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 105;

struct Node{
    char tp;
    int lc, rc;
}tree[maxn];

char str[maxn];
map<char, bool> mp;

bool cmp(int k){
    if(islower(tree[k].tp)){
        return mp[tree[k].tp];
    }
    else{
        if(tree[k].tp == 'K'){
            return cmp(tree[k].lc) && cmp(tree[k].rc);
        }
        else if(tree[k].tp == 'A'){
            return cmp(tree[k].lc) || cmp(tree[k].rc);
        }
        else if(tree[k].tp == 'N'){
            return !cmp(tree[k].lc);
        }
        else if(tree[k].tp == 'C'){
            return !cmp(tree[k].lc) || cmp(tree[k].rc);
        }
        else{
            return cmp(tree[k].lc) == cmp(tree[k].rc);
        }
    }
}

int idx = 0;

int build(){
    int th = idx;
    char ch = str[idx++];
    tree[th].tp = ch;
    if(islower(ch)){
        return th;
    }
    else if(ch == 'N'){
        tree[th].lc = build();
    }
    else{
        tree[th].lc = build();
        tree[th].rc = build();
    }
    return th;
}

int main()
{
    while(~scanf("%s", str) && str[0] != '0'){
        int n = strlen(str);
        idx = 0;
        build();
        bool flag = true;
        for(int S = 0; S < (1 << 5); S++){
            for(int i = 0; i < 5; i++){
                mp['p' + i] = ((S & (1 << i)) > 0);
            }
            flag = flag && cmp(0);
        }
        if(flag){
            puts("tautology");
        }
        else{
            puts("not");
        }
    }
    return 0;
}
