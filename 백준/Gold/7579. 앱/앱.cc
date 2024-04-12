// 7579
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int n, m;
int M[101];
int cost[101];
int dp[101][10101];
int costSum;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> M[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> cost[i];
        costSum+=cost[i];
    }

    ans = costSum + 1;
    

    for(int i = 1; i<=n; i++){
        for(int j = costSum; j>=0; j--){
            dp[i][j] = dp[i-1][j];
            if(j-cost[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + M[i]);
            }

            if(dp[i][j] >= m){
                ans = min(j, ans);
            }
        }
    }



    cout << ans;
}
