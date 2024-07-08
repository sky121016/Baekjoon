#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int dp[1010][1010];
int p[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> p[i];
    }

    for(int i = 0; i<=n; i++){
        dp[0][i] = 10101;
    }


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i <= j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-i] + p[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << dp[n][n];
}

