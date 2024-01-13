// 1149
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dp[1001][3];
int rgb[1001][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> rgb[i][j];
        }
    }

    for(int i = 0; i<3; i++){
        dp[0][i] = rgb[0][i];
    }

    for(int i = 1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }

    int M;
    M = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

    cout << M;
}


