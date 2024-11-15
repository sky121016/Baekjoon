#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int cnt = 0;
    int a = x;
    
    while(cnt < n){
        answer.push_back(a);
        
        a += x;
        cnt++;
    }
    
    return answer;
}