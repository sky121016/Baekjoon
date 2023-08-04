// 2193 이친수
#include<iostream>
#include<vector>

using namespace std;

long long dp[91];       // dp[0] = 0
int n;

long long pinary(int a){
    dp[1] = 1;

    for(int i = 2; i<=a; i++){
        dp[i] = dp[i - 1] + dp[i - 2];      
        // dp[i]는
        // 1이 연속되지 않는 i-1자리 문자열 + "0"       => dp[i-1] 
        // 1이 연속되지 않는 i-2자리 문자열 + "0 1"     => dp[i-2]
    }

    return dp[a];
}

int main(){
    cin >> n;
    
    pinary(n);
    cout << dp[n];
}

