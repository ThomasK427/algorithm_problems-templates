#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

string str;

int main()
{
    int n;
    while(~scanf("%d", &n)){
        getchar();
        getline(cin, str);
        stringstream ss(str);
        int res = 0;
        while(ss >> str){
            int cnt = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        printf("%d\n", res);
    }
    return 0;
}
