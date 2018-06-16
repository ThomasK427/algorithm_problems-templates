#include <bits/stdc++.h>
using namespace std;

int ar[10], br[5][5], cr[5][5], dr[5][5];

bool check(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(br[i][j] != 0 && br[i][j] != cr[i][j]){
                return false;
            }
        }
    }
    int sum = cr[0][0] + cr[0][1] + cr[0][2];
    for(int i = 0; i < 3; i++){
        int s = 0;
        for(int j = 0; j < 3; j++){
            s += cr[i][j];
        }
        if(sum != s){
            return false;
        }
    }
    for(int j = 0; j < 3; j++){
        int s = 0;
        for(int i = 0; i < 3; i++){
            s += cr[i][j];
        }
        if(sum != s){
            return false;
        }
    }
    if(sum != cr[0][0] + cr[1][1] + cr[2][2]){
        return false;
    }
    if(sum != cr[2][0] + cr[1][1] + cr[0][2]){
        return false;
    }
    return true;
}

int main()
{
    for(int i = 0; i < 9; i++){
        ar[i] = i + 1;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &br[i][j]);
        }
    }
    int cnt = 0;
    do{
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cr[i][j] = ar[i * 3 + j];
            }
        }
        if(check()){
            cnt++;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    dr[i][j] = cr[i][j];
                }
            }
        }
    }while(next_permutation(ar, ar + 9));
    if(cnt == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d%c", dr[i][j], j == 2 ? '\n' : ' ');
            }
        }
    }
    else{
        puts("Too Many");
    }
    return 0;
}
