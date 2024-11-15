#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0 = 48
// a = 97
// A = 65

string solution(string s) {
    for(int i = 0; i<s.length(); i++){
        if(s[i] == ' '){
            continue;
        }
        
        if(int(s[i]) < 97 && int(s[i]) > 64){
            if(i >= 1){
                if(s[i-1] != ' '){
                    s[i] = s[i] + 32;
                }
            }else{
                s[i] = s[i] + 32;
            }
            
        }
        
        if(int(s[i]) > 96){
            if(i>= 1){
                if(s[i-1] == ' '){
                    s[i] = s[i] - 32;
                }
            }else{
                s[i] = s[i] - 32;
            }
        }
    }    

    return s;
    

}