// 11725
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int dp[101][101];
int a[101];
int sum[101];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }


    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = -999999;
        }
    }
    dp[1][1] = sum[1];
    
 
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = dp[i - 1][j];

            if(j == 1){
                dp[i][j] = max(dp[i][j], sum[i]);
            }

            for(int k = 0; k<=i-2; k++){
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[i] - sum[k + 1]);
            }
        }
    }

    cout << dp[n][m];
}
