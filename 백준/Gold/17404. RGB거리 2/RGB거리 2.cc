// 17404
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int r[1001][3];
int g[1001][3];
int b[1001][3];

int dp[3][1001][3];

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
        for(int j = 0; j<3; j++){
            dp[i][0][j] = 1001;
        }

        dp[i][0][i] = rgb[0][i];
        dp[i][1][i] = 1001;
        dp[i][n-1][i] = 1001;
    }


    for(int i = 0; i<3; i++){
        for(int j = 1; j<n; j++){
            dp[i][j][0] = min(dp[i][j-1][1], dp[i][j-1][2]) + rgb[j][0];
            dp[i][j][1] = min(dp[i][j-1][0], dp[i][j-1][2]) + rgb[j][1];
            dp[i][j][2] = min(dp[i][j-1][0], dp[i][j-1][1]) + rgb[j][2];
        }
    }

    int M;
    int ans[3];

    ans[0] = min(dp[0][n - 1][1], dp[0][n - 1][2]);
    ans[1] = min(dp[1][n - 1][0], dp[1][n - 1][2]);
    ans[2] = min(dp[2][n - 1][0], dp[2][n - 1][1]);

    M = min(min(ans[0], ans[1]), ans[2]);
    cout << M;
}
