// 9012
#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> s;
int T;
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for(int i = 0; i<T; i++){

        cin >> str;

        for(int j = 0; j < str.length(); j++){
            if(str[j] == '('){
                s.push(str[j]);
            }else{
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else{
                    s.push(str[j]);
                }
            }
        }


        if(s.empty()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

        while(!s.empty()){
            s.pop();
        }
    }
}
