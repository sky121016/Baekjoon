// 9461 파도반 수열
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

long long dp[101];

long long P(int n){
    if(n<=3){
        return dp[n] = 1;
    }else if(n<=5){
        return dp[n] = 2;
    }
    
    if(dp[n] != 0){
        return dp[n];
    }
    
    return dp[n] = P(n-1) + P(n-5);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    for(int i = 0; i<t; i++){
        cin >> n;
        cout<<P(n)<<"\n";
    }
}

