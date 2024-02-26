// 2109
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
long long dp[31];

long long DP(int num){

    dp[0] = 1;

    for(int i = 2; i<=num; i+=2){
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j<=i; j+=2){
            dp[i] += dp[i - j] * 2;
        }

    }

    return dp[num];
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout<<DP(n);

}