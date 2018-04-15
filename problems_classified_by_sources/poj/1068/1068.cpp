#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 30;

int ar[maxn], d[maxn];
char str[maxn * 2];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        ar[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
        }
        for(int i = 1; i <= n; i++){
            d[i] = ar[i] - ar[i - 1];
        }
        int p = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= d[i]; j++){
                str[p++] = '(';
            }
            str[p++] = ')';
        }
        str[p] = '\0';
        stack<int> s;
        vector<int> v;
        for(int i = 0; i < p; i++){
            if(str[i] == '('){
                s.push(i);
            }
            else{
                int c = 0;
                for(int j = s.top(); j <= i; j++){
                    if(str[j] == ')'){
                        c++;
                    }
                }
                s.pop();
                v.push_back(c);
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d%c", v[i], i + 1 == v.size() ? '\n' : ' ');
        }
    }
    return 0;
}
