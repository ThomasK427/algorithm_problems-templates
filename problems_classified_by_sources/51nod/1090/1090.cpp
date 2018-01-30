#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int ar[maxn];
set<int> st;
set<int> used;

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", ar + i);
        st.insert(ar[i]);
    }
    bool flag = false;
    sort(ar, ar + N);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int a = ar[i], b = ar[j], c = 0 - ar[i] - ar[j];
            if(st.find(c) != st.end() && a < b && b < c){
                used.insert(a);
                used.insert(b);
                used.insert(c);
                printf("%d %d %d\n", a, b, c);
                flag = true;
            }
        }
    }
    if(!flag){
        printf("No Solution\n");
    }
    return 0;
}
