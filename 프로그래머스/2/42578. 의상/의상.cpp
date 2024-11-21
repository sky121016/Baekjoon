#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    for(int i = 0; i<clothes.size(); i++){
        if(m.find(clothes[i][1]) == m.end()){
            m.insert({clothes[i][1],1});
        }else{
            m[clothes[i][1]]++;
        }

    }
    
    int result = 1;
    for(auto iter = m.begin(); iter!=m.end() ;++iter){
        result *= (iter->second+1);
    }
    
    return result-1;
    
}