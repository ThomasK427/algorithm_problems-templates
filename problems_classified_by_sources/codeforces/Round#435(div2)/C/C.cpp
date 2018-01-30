#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, x;
    scanf("%d%d", &n, &x);
    if(n == 1){
        puts("YES");
        printf("%d\n", x);
    }
    else if(n == 2){
        if(x == 0){
            puts("NO");
        }
        else{
            printf("YES\n0 %d\n", x);
        }
    }
    else{
        set<int> st;
        bool flag = false;
        int sum = 0;
        for(int i = 1; i <= n - 2; i++){
            sum = (sum ^ i);
            st.insert(i);
        }
        for(int i = n - 1; i <= 1000000; i++){
            int y = (x ^ sum ^ i);
            if(!st.count(y) && y <= 1000000 && y != i){
                st.insert(i);
                st.insert(y);
                flag = true;
                break;
            }
        }
        if(!flag){
            sum = (sum ^ (n - 2));
            st.erase(n - 2);
            for(int i = n - 1; i <= 1000000; i++){
                for(int j = n - 2; j < i; j++){
                    int y = (x ^ sum ^ i ^ j);
                    if(!st.count(y) && (y <= 1000000) && (y != i) && (y != j)){
                        st.insert(i);
                        st.insert(j);
                        st.insert(y);
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        if(flag){
            puts("YES");
            bool isFirst = true;
            for(set<int>::iterator it = st.begin(); it != st.end(); it++){
                if(!isFirst){
                    putchar(' ');
                }
                isFirst = false;
                printf("%d", *it);
            }
            putchar('\n');
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
