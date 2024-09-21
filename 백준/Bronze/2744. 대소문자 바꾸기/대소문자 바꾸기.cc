// 2638
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for(int i = 0; i<s.length(); i++){  


        if(s[i] >= 'a'){
            cout<<char(s[i]-32);
        }else{
            cout<<char(s[i]+32);
        }
    }
}


