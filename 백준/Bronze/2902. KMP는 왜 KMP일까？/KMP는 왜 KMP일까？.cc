// 17265

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

string s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s;

    cin >> s;

    for(int i = 0; i<s.length(); i++){
        if(i == 0){
            cout << s[i];
            continue;
        }

        if(s[i] == '-'){
            cout << s[i+1];
            continue;
        }
    }

}