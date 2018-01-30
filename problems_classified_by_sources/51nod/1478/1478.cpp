#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
const int maxn = 1000005;

char str[maxn];
int d[maxn], mp[maxn];
stack<int> s;

int main()
{
    gets(str);
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            s.push(i);
        }
        else if(!s.empty()){
            for(int j = s.top(); j <= i; j++){
                d[j] = 1;
            }
            s.pop();
        }
    }
    int p = 0;
    while(p < n){
        if(d[p]){
            int len = 0;
            while(d[p]){
                p++;
                len++;
            }
            mp[len]++;
        }
        else{
            p++;
        }
    }
    mp[0] = 1;
    for(int i = n; i >= 0; i--){
        if(mp[i]){
            printf("%d %d\n", i, mp[i]);
            break;
        }
    }
    return 0;
}
