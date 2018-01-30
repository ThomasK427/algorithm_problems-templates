#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

char g[20][20];

bool check(int i, int j)
{
    int a = 1;
    int x = i + 1, y = j;
    while(x < 10){
        if(g[x][y] == 'X'){
            a++;
            x++;
        }
        else{
            break;
        }
    }
    x = i - 1;
    while(x >= 0){
        if(g[x][y] == 'X'){
            a++;
            x--;
        }
        else{
            break;
        }
    }
    if(a >= 5)return true;
    x = i;
    y = j + 1;
    a = 1;
    while(y < 10){
        if(g[x][y] == 'X'){
            a++;
            y++;
        }
        else{
            break;
        }
    }
    y = j - 1;
    while(y >= 0){
        if(g[x][y] == 'X'){
            a++;
            y--;
        }
        else{
            break;
        }
    }
    if(a >= 5)return true;
    x = i + 1;
    y = j + 1;
    a = 1;
    while(x < 10 && y < 10){
        if(g[x][y] == 'X'){
            a++;
            x++;
            y++;
        }
        else{
            break;
        }
    }
    x = i - 1;
    y = j - 1;
    while(x >= 0 && y >= 0){
        if(g[x][y] == 'X'){
            a++;
            x--;
            y--;
        }
        else{
            break;
        }
    }
    if(a >= 5)return true;
    x = i + 1;
    y = j - 1;
    a = 1;
    while(x < 10 && y >= 0){
        if(g[x][y] == 'X'){
            a++;
            x++;
            y--;
        }
        else{
            break;
        }
    }
    x = i - 1;
    y = j + 1;
    while(x >= 0 && y < 10){
        if(g[x][y] == 'X'){
            a++;
            x--;
            y++;
        }
        else{
            break;
        }
    }
    if(a >= 5)return true;
    return false;
}

int main()
{
    for(int i = 0; i < 10; i++){
        scanf("%s", g[i]);
    }
    bool flag = false;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(g[i][j] == '.' && check(i, j)){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
