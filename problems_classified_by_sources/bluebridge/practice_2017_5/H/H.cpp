#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    string op, name;
    int score;
    while((cin >> op) && (op != "end")){
        if(op == "insert"){
            cin >> name >> score;
            mp[name] = max(mp[name], score);
        }
        else{
            cin >> name;
            if(mp.count(name)){
                cout << mp[name] << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
