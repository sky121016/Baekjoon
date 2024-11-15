#include <string>
#include <vector>
#include<iostream>

using namespace std;

int zeroCnt;
int oneCnt;
int cnt;
vector<char> tempS;
vector<int> ans;

vector<int> solution(string s) {
    while(s != "1"){
        cnt++;
        
        oneCnt = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '0'){
                zeroCnt++;
            }else{
                oneCnt++;
            }
        }
        
        int c = oneCnt;
        
        while(c > 0){
            if(c % 2 == 0){
                tempS.push_back('0');
            }else{
                tempS.push_back('1');
            }
            
            c /= 2;
        }
        
        s = "";
        while(!tempS.empty()){
            s += tempS.back();
            tempS.pop_back();
        }
        
        
    }
    
    ans.push_back(cnt);
    ans.push_back(zeroCnt);
    
    return ans;
    
}