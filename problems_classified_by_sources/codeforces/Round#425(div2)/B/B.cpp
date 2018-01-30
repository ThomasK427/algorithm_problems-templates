#include <bits/stdc++.h>
using namespace std;
typedef long long L;

char gd[100005], pattern[100005], str[100005];
int n;

int main()
{
    //freopen("test.txt", stdin);
    while(cin >> gd >> pattern >> n){
        set<char> good, bad;
        int lgd = strlen(gd), lp = strlen(pattern);
        for(int i = 0; i < lgd; i++){
            good.insert(gd[i]);
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(good.find(ch) == good.end()){
                bad.insert(ch);
            }
        }
//        for(set<char>::iterator it = bad.begin(); it != bad.end(); it++){
//            cout << *it << ' ';
//        }
//        cout << endl;
        int p = -1;
        for(int i = 0; i < lp; i++){
                if(pattern[i] == '*'){
                    p = i;
                    break;
                }
            }
//        cout << "p = " << p << endl;
        while(n--){
            scanf("%s", str);
//            cout << "str = " << str << endl;
            bool flag = true;
            int len = strlen(str);
            if(p == -1){
                if(lp != len){
                    flag = false;
//                    puts("WA 1");
                    goto HERE;
                }
                else{
                    for(int j = 0; j < len; j++){
                        if(str[j] != pattern[j]){
                            if(pattern[j] != '?' || good.find(str[j]) == good.end()){
                                flag = false;
//                                puts("WA 2");
                                goto HERE;
                            }
                        }
                    }
                }
            }
            else{
                if(len < p){
                    flag = false;
//                    puts("WA 3");
                    goto HERE;
                }
                else{
                    for(int j = 0; j < p; j++){
                        if(str[j] != pattern[j]){
                            if(pattern[j] != '?' || good.find(str[j]) == good.end()){
                                flag = false;
 //                               puts("WA 4");
                                goto HERE;
                            }
                        }
                    }
                    if(lp == len + 1 && pattern[lp-1] == '*'){
                        flag = true;
//                        puts("AC 5");
                        goto HERE;
                    }
                    if(len < lp - 1){
                        flag = false;
//                        puts("WA 6");
                        goto HERE;
                    }
                    int k = len - 1;
                    for(int j = lp - 1, k = len - 1; j > p; j--, k--){
                        if(str[k] != pattern[j]){
                            if(pattern[j] != '?' || good.find(str[k]) == good.end()){
                                flag = false;
//                                puts("WA 7");
                                goto HERE;
                            }
                        }
                    }
 //                   cout << "k = " << k << endl;
                    for(int j = p; j <= k; j++){
                        if(bad.find(str[j]) == bad.end()){
                            flag = false;
//                            cout << "j = " << j << endl;
//                            printf("%c\n", str[j]);
//                            puts("WA 8");
                            goto HERE;
                        }
                    }
                }
            }
            HERE:;
            if(flag){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}
