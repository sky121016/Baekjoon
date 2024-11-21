#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int n;
int a[1001];
int dp[1001];
int INF = 99999999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n; i++){
        dp[i] = INF;
    }

    dp[1] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=a[i]; j++){
            dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }



    if(dp[n] == INF){
        cout << -1;
    }else{
        cout << dp[n];
    }
}