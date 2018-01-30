#include <bits/stdc++.h>
using namespace std;

char g1[10][10], g2[10][10];

int main()
{
    //freopen("test.txt", "r", stdin);
    int T, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &K);
        K--;
        for(int i = 0; i < 6; i++){
            scanf("%s", g1[i]);
        }
        for(int i = 0; i < 6; i++){
            scanf("%s", g2[i]);
        }
        vector<char> v[5];
        for(int j = 0; j < 5; j++){
            for(int i = 0; i < 6; i++){
                for(int k = 0; k < 6; k++){
                    if(g1[i][j] == g2[k][j]){
                        v[j].push_back(g1[i][j]);
                    }
                }
            }
        }
        for(int j = 0; j < 5; j++){
            sort(v[j].begin(), v[j].end());
            unique(v[j].begin(), v[j].end());
        }
        string ans = "";
        for(int j = 0; j < 5; j++){
            if(v[j].size() == 0){
                ans = "NO";
                goto HERE;
            }
        }
        for(int j = 0; j < 5; j++){
            int product = 1;
            for(int i = j + 1; i < 5; i++){
                product *= int(v[i].size());
            }
            int p = K / product;
            K %= product;
            if(p >= int(v[j].size())){
                ans = "NO";
                break;
            }
            else{
                ans += v[j][p];
            }
        }
        HERE:;
        cout << ans << endl;
    }
    return 0;
}
