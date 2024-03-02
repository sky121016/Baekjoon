// 14921
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
stack<char> s;
string str;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> str;
        for(int j = 0; j<str.length(); j++){
            if(!s.empty() && s.top() == str[j]){
                s.pop();
            }else{
                s.push(str[j]);
            }
        }

        if(s.empty()){
            ans++;
        }

        while(!s.empty()){
            s.pop();
        }
    }

    cout << ans;
}