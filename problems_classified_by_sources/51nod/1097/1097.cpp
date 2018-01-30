#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

string num[maxn];

bool cmp(const string& s1, const string& s2){
    return s1 + s2 < s2 + s1;
}

string scf(){
    char str[100];
    scanf("%s", str);
    return str;
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        num[i] = scf();
    }
    sort(num, num + N, cmp);
    string ans;
    for(int i = 0; i < N; i++){
        ans += num[i];
    }
    int len = ans.size();
    for(int i = 0; i < len; i++){
        putchar(ans[i]);
        if((i + 1) % 1000 == 0){
            putchar('\n');
        }
    }
    if(len % 1000){
        putchar('\n');
    }
    return 0;
}
