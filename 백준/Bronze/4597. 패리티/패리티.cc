#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

string s;
int cnt;
int parity;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> s;
        cnt = 0;
        
        if(s == "#"){
            break;
        }

        for(int i = 0; i<s.length()-1; i++){
            if(s[i] == '1'){
                cnt++;
            }
        }

        if(s[s.length()-1] == 'e'){
            parity = 0;
        }else{
            parity = 1;
        }

        if(parity == 0){
            if(cnt % 2 == 0){
                s[s.length()-1] = '0';
            }else{
                s[s.length()-1] = '1';
            }
        }else{
            if(cnt % 2 == 0){
                s[s.length()-1] = '1';
            }else{
                s[s.length()-1] = '0';
            }
        }

        cout << s << "\n";
    }

}

