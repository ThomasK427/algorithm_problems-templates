#include <bits/stdc++.h>
using namespace std;

char g1[10][10], g2[10][10];
char str[10];

int main()
{
    //freopen("test.txt", "r", stdin);
    int T, K;
    scanf("%d", &T);
    while(T--){
        int cnt = 0;
        scanf("%d", &K);
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
        if(K > int(v[0].size() * v[1].size() * v[2].size() * v[3].size() * v[4].size())){
            printf("NO\n");
            goto HERE;
        }
        cnt = 0;
        for(int a = 0; a < int(v[0].size()); a++){
            for(int b = 0; b < int(v[1].size()); b++){
                for(int c = 0; c < int(v[2].size()); c++){
                    for(int d = 0; d < int(v[3].size()); d++){
                        for(int e = 0; e < int(v[4].size()); e++){
                            cnt++;
                            if(cnt == K){
                                printf("%c%c%c%c%c\n", v[0][a], v[1][b], v[2][c], v[3][d], v[4][e]);
                                goto HERE;
                            }
                        }
                    }
                }
            }
        }
        printf("NO\n");
        HERE:;
    }
    return 0;
}

