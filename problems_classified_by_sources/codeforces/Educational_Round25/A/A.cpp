#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

char str[200];

int main()
{
    int n;
    while(~scanf("%d", &n)){
        scanf("%s", str);
        int cnt = 0;
        vector<int> ans;
        int p = 0;
        while(p < n){
            if(str[p] == '1'){
                cnt++;
                p++;
            }
            else{
                ans.push_back(cnt);
                cnt = 0;
                p++;
            }
        }
        ans.push_back(cnt);
        for(int i = 0; i < ans.size(); i++){
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
