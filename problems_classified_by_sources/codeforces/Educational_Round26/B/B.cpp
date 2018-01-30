#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char g[maxn][maxn];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; i++){
            scanf("%s", g[i]);
        }
        bool ans = true;
        bool flag1 = true, flag2 = true;
        if((n % 3 != 0) && (m % 3 != 0)){
            ans = false;
            goto HERE;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((g[i][j] != 'R') && (g[i][j] != 'G') && (g[i][j] != 'B')){
                    ans = false;
                    goto HERE;
                }
            }
        }
        if(n % 3 != 0){
            flag1 = false;
        }
        else{
            set<char> s;
            int k = n / 3;
            s.insert(g[0][0]);
            for(int i = 0; i < k; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] != g[0][0]){
                        flag1 = false;
                        goto F1;
                    }
                }
            }
            if(s.find(g[k][0]) != s.end()){
                flag1 = false;
                goto F1;
            }
            s.insert(g[k][0]);
            for(int i = k; i < 2 * k; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] != g[k][0]){
                        flag1 = false;
                        goto F1;
                    }
                }
            }
            if(s.find(g[2 * k][0]) != s.end()){
                flag1 = false;
                goto F1;
            }
            s.insert(g[2 * k][0]);
            for(int i = 2 * k; i < 3 * k; i++){
                for(int j = 0; j < m; j++){
                    if(g[i][j] != g[2 * k][0]){
                        flag1 = false;
                        goto F1;
                    }
                }
            }
        }
        F1:;
        if(m % 3 != 0){
            flag2 = false;
        }
        else{
            set<char> s;
            int k = m / 3;
            s.insert(g[0][0]);
            for(int j = 0; j < k; j++){
                for(int i = 0; i < n; i++){
                    if(g[i][j] != g[0][0]){
                        flag2 = false;
                        goto F2;
                    }
                }
            }
            if(s.find(g[0][k]) != s.end()){
                flag2 = false;
                goto F2;
            }
            s.insert(g[0][k]);
            for(int j = k; j < 2 * k; j++){
                for(int i = 0; i < n; i++){
                    if(g[i][j] != g[0][k]){
                        flag2 = false;
                        goto F2;
                    }
                }
            }
            if(s.find(g[0][2 * k]) != s.end()){
                flag2 = false;
                goto F2;
            }
            s.insert(g[0][2 * k]);
            for(int j = 2 * k; j < 3 * k; j++){
                for(int i = 0; i < n; i++){
                    if(g[i][j] != g[0][2 * k]){
                        flag2 = false;
                        goto F2;
                    }
                }
            }
        }
        F2:;
        if(!flag1 && !flag2){
            ans = false;
        }
        HERE:;
        if(ans){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
