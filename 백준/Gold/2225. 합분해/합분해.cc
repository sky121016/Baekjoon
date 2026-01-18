// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int dp[201][201];
int NUM = 1000000000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i<=n; i++){
        dp[1][i] = 1;
    }

    for(int i = 0; i<=k; i++){
        dp[i][0] = 1;
    }

    for(int i = 2; i<=k; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % NUM;
        }
    }


    cout << dp[k][n];
}
