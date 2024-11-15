#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> a;
    
    int start = 0;
    
    string temp;
    for(int i = 0; i<s.length(); i++){
        
        if(s[i] == ' '){
            temp = "";
            for(int j = start; j<i; j++){
                temp += s[j];            
            }
            a.push_back(stoi(temp));
            start = i+1;
        }
    }
    
    temp = "";
    
    for(int j = start; j<s.length(); j++){
        temp += s[j];            
    }
    a.push_back(stoi(temp));
    
    int Max = *max_element(a.begin(), a.end());
    int Min = *min_element(a.begin(), a.end());
    
    answer += to_string(Min);
    answer += " ";
    answer += to_string(Max);
    
    return answer;
}