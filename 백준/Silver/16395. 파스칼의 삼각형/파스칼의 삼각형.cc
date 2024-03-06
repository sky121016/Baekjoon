// 16395 파스칼
#include<iostream>
#include<vector>
using namespace std;

int n, k;
int dp[31][31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        dp[i][1] = 1;
        dp[i][i] = 1;
    }

    for(int i = 3; i<=n; i++){
        for(int j = 2; j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }


    cout << dp[n][k];
}
