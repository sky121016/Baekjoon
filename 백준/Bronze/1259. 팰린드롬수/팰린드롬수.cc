

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>

using namespace std;

string s;
bool flag;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(1){
        cin >> s;
        if(s == "0"){
            return 0;
        }

        flag = true;

        for(int i = 0; i<s.length()/2; i++){
            if(s[i] != s[s.length()-i-1]){
                cout<<"no\n";
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"yes\n";
        }
    }


}

