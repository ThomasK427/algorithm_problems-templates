#include <bits/stdc++.h>
using namespace std;
int ar[20] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isleap(int x){
    return (x % 400 == 0) || (x % 4 == 0 && x % 100 != 0);
}

bool check(int y, int m, int d){
    if(isleap(y)){
        ar[2]++;
    }
    bool flag = true;
    if(m >= 1 && m <= 12){
        if(d >= 1 && d <= ar[m]){
            ;
        }
        else{
            flag = false;
        }
    }
    else{
        flag = false;
    }
    if(isleap(y)){
        ar[2]--;
    }
    return flag;
}

int trans(int y){
    if(y >= 60){
        y += 1900;
    }
    else{
        y += 2000;
    }
    return y;
}

int main()
{
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    set<int> st;
    if(check(a, b, c)){
        st.insert(a * 10000 + b * 100 + c);
    }
    if(check(c, a, b)){
        st.insert(c * 10000 + a * 100 + b);
    }
    if(check(c, b, a)){
        st.insert(c * 10000 + b * 100 + a);
    }
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        int o = *it;
        a = o / 10000;
        b = (o % 10000) / 100;
        c = o % 100;
        printf("%d-%02d-%02d\n", trans(a), b, c);
    }
    return 0;
}
