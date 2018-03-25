#include <bits/stdc++.h>
using namespace std;


int main()
{
    //19683
    int ans = 0;
    for(int S = 0; S < 19683; S++){
        stack<int> num, numb, op, opb;
        int x = S;
        for(int i = 1; i < 10; i++){
            numb.push(11 - i);
            opb.push(x % 3);
            x /= 3;
        }
        numb.push(1);
        stack<int> nc = numb, nn = opb;
//        while(!nc.empty()){
//            cout << nc.top() << " ";
//            nc.pop();
//        }
//        cout << endl;
//        while(!nn.empty()){
//            if(nn.top() == 0){
//                cout << "+" << " ";
//            }
//            else if(nn.top() == 1){
//                cout << "-" << " ";
//            }
//            else{
//                cout << "*" << " ";
//            }
//            nn.pop();
//        }
//        cout << endl;
        num.push(numb.top());
        numb.pop();
        while(!opb.empty()){
            int opr = opb.top();
            opb.pop();
            if(!opb.empty() && opb.top() == 2){
                op.push(opr);
                num.push(numb.top());
                numb.pop();
            }
            else{
                int num2 = numb.top();
                numb.pop();
                int num1 = num.top();
                num.pop();
                if(opr == 2){
                    //cout << num1 << " * " << num2 << endl;
                    num.push(num1 * num2);
                }
                else if(opr == 1){
                    num.push(num1 - num2);
                    //cout << num1 << " - " << num2 << endl;
                }
                else{
                    num.push(num1 + num2);
                   // cout << num1 << " + " << num2 << endl;
                }
                while(!op.empty()){
                    num2 = num.top();
                    num.pop();
                    num1 = num.top();
                    num.pop();
                    opr = op.top();
                    op.pop();
                    if(opr == 2){
                       // cout << num1 << " * " << num2 << endl;
                        num.push(num1 * num2);
                    }
                    else if(opr == 1){
                        num.push(num1 - num2);
                       // cout << num1 << " - " << num2 << endl;
                    }
                    else{
                        num.push(num1 + num2);
                       // cout << num1 << " + " << num2 << endl;
                    }
                }
            }
        }
       // cout << num.size() << endl;
       // cout << num.top() << endl;
        if(num.top() == 0){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
