#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

char str[maxn];

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    vector<int> a, b;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            flag = true;
        }
        if(flag){
            a.push_back(str[i] - '0');
        }
    }
    scanf("%s", str);
    n = strlen(str);
    flag = false;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            flag = true;
        }
        if(flag){
            b.push_back(str[i] - '0');
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size() < b.size()){
        int m = int(b.size()) - int(a.size());
        for(int i = 0; i < m; i++){
            a.push_back(0);
        }
    }
    else{
        int m = int(a.size()) - int(b.size());
        for(int i = 0; i < m; i++){
            b.push_back(0);
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    n = a.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            continue;
        }
        else if(a[i] > b[i]){
            if(i >= n - 2 || a[i] - b[i] >= 2){
                ans = 1;
                break;
            }
            else{
                a[i + 1]++;
                a[i + 2]++;
            }
        }
        else if(a[i] < b[i]){
            if(i >= n - 2 || b[i] - a[i] >= 2){
                ans = -1;
                break;
            }
            else{
                b[i + 1]++;
                b[i + 2]++;
            }
        }
    }
    if(ans == 1){
        puts(">");
    }
    else if(ans == -1){
        puts("<");
    }
    else{
        puts("=");
    }
    return 0;
}
