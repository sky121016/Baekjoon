#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int n;
int dp[1001][3];
int cost[1001][3];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i = 1; i<=n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int i = 1; i<=n; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}
