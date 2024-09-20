// 2638
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int t, w;

int dp[3][32][1010];
int jadu[1010];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;

    for(int i = 1; i<=t; i++){
        cin>>jadu[i];
    }

    // for(int i = 0; i<=t; i++){
    //     for(int j =0; j<=w+1; j++){
    //         dp[0][j][i] = -1;
    //         dp[1][j][i] = -1;
    //         dp[2][j][i] = -1;
    //     }
    // }

    for(int i = 1; i<=t; i++){
        for(int j = 1; j<=w+1; j++){
            if(jadu[i] == 1){
                dp[1][j][i] = max(dp[1][j][i-1] + 1, dp[2][j-1][i-1] + 1);
                dp[2][j][i] = max(dp[2][j][i-1], dp[1][j-1][i-1]);
            }else{
                if(i == 1 && j == 1){
                    continue;
                }

                dp[1][j][i] = max(dp[1][j][i-1], dp[2][j-1][i-1]);
                dp[2][j][i] = max(dp[2][j][i - 1] + 1, dp[1][j - 1][i - 1] + 1);
            }
        }
    }



    for(int i = 1; i<= w+1; i++){
        ans = max(max(dp[1][i][t], dp[2][i][t]), ans);
    }

    cout << ans;
}
