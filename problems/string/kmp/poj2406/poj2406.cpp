#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1005;

int next[maxn];

void cal_next(char* str){
    int n = strlen(str);
    next[0] = -1;
    int k = -1;
    for(int q = 1; q < n; q++){
        while(k > -1 && str[k + 1] != str[q]){
            k = next[k];
        }
        if(str[k + 1] == str[q]){
            k++;
        }
        next[q] = k;
    }
}

int kmp(char* text, char* pattern){
    int n = strlen(text), m = strlen(pattern);
    cal_next(pattern);

}

int main()
{
    return 0;
}
