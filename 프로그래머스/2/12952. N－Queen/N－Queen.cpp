#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int q[13];
int ans;
int N;

bool check(int idx){
    for(int i = 0; i<idx; i++){
        if(q[i] == q[idx] || abs(q[idx] - q[i]) == idx-i){
            return false;
        }
    }
    return true;
}

void queen(int cnt){
    if(cnt == N){
        ans++; 
        return;
    }
    
    for(int i = 0; i<N; i++){
        q[cnt] = i;
        if(check(cnt)){
            queen(cnt+1);
        }
        
        
    }
}



int solution(int n) {
    N = n;
    
    queen(0);
    
    cout<<ans;
    return ans;
    
}