#include <string>
#include <vector>

using namespace std;

int dp[101010];

int Fibo(int x){
    if(x == 1){
        return dp[1] = 1;
    }
    
    if(x == 0){
        return dp[0] = 0;
    }
    
    if(dp[x] != 0){
        return dp[x];
    }
    
    return dp[x] = (Fibo(x-1) + Fibo(x-2)) % 1234567;
}

int solution(int n) {
    return Fibo(n);
}