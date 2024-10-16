// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

string str;
stack<char> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 0; i<str.length(); i++){
        if (s.empty()){
            s.push(str[i]);
            continue;
        }

        if(str[i] == ')'){
            if(s.top() == '('){
                s.pop();
            }else{
                s.push(str[i]);
            }
        }else{
            s.push(str[i]);
        }
    }

    cout << s.size();
}
