// 1918 후위표기
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

stack<char> op;
string question;


int main()
{
    // ABC는 바로 출력
    // 스택에 op 저장.
    // 우선순위
    // A~Z 65 ~ 90

    cin >> question;
    int len = question.length();

    for (int i = 0; i < len; i++){
        if (0 <= question[i] - 'A' && question[i] - 'A' <= 26){ // 알파벳이면
            cout << question[i];
        }else{
          
            if (question[i] == '('){
                op.push(question[i]);
            } else if(question[i] == '*' || question[i] == '/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(question[i]);
            } else if(question[i] == '+' || question[i] == '-'){
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.push(question[i]);
            } else if(question[i] == ')'){
                while (!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();  
            }
            
           
        }
    }

    while (!op.empty()){
        cout << op.top();
        op.pop();
    }
}