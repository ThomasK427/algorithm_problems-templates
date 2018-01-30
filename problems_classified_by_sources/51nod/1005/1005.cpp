#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

char a[maxn];
char b[maxn];
int ans[maxn];

int cmp(char A[], char B[], int n)
{
    for(int i = n - 1; i >= 0; i--){
        if(A[i] == B[i]){
            continuel
        }
        else if(A[i] < B[i]){
            return -1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%s%s", a, b);
    if(a[0] != '-' && b[0] != '-'){
        int s1 = strlen(a), s2 = strlen(b);
        reverse(a, a + s1);
        reverse(b, b + s2);
        int c = 0;
        char *p, *q;
        if(s1 > s2){
            p = a;
            q = b;
        }
        else{
            p = b;
            q = a;
            swap(s1, s2);
        }
        for(int i = 0; i < s2; i++){
            ans[i] = ((p[i] - '0') + (q[i] - '0') + c) % 10;
            c = ((p[i] - '0') + (q[i] - '0') + c) / 10;
        }
        for(int i = s2; i < s1; i++){
            ans[i] = ((p[i] - '0') + c) % 10;
            c = ((p[i] - '0') + c) / 10;
        }
        if(c > 0){
            ans[s1++] = c;
        }
        reverse(ans, ans + s1);
        for(int i = 0; i < s1; i++){
            putchar(ans[i] + '0');
        }
        putchar('\n');
    }
    else if(a[0] == '-' && b[0] == '-'){
        int s1 = strlen(a), s2 = strlen(b);
        reverse(a, a + s1);
        reverse(b, b + s2);
        s1--;
        s2--;
        int c = 0;
        char *p, *q;
        if(s1 > s2){
            p = a;
            q = b;
        }
        else{
            p = b;
            q = a;
            swap(s1, s2);
        }
        for(int i = 0; i < s2; i++){
            ans[i] = ((p[i] - '0') + (q[i] - '0') + c) % 10;
            c = ((p[i] - '0') + (q[i] - '0') + c) / 10;
        }
        for(int i = s2; i < s1; i++){
            ans[i] = ((p[i] - '0') + c) % 10;
            c = ((p[i] - '0') + c) / 10;
        }
        if(c > 0){
            ans[s1++] = c;
        }
        reverse(ans, ans + s1);
        putchar('-');
        for(int i = 0; i < s1; i++){
            putchar(ans[i] + '0');
        }
        putchar('\n');
    }
    else if(a[0] != '-' && b[0] == '-'){
        int s1 = strlen(a), s2 = strlen(b);
        reverse(a, a + s1);
        reverse(b, b + s2);
        s2--;
        if(s1 > s2){

        }
        else if(s1 < s2){

        }
        else{
            int p = cmp(a, b, s1);
            if(p == 0){
                puts("0");
            }
            else if(p == 1){

            }
            else{

            }
        }
    }
    else{

    }
    return 0;
}
