// 11057
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

long long n;
long long dp[1010][11];
long long sum;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<=9; i++){
        dp[1][i] = 1;
    }
    
    for(int i = 2; i<=n; i++){
        dp[i][0] = 1;

        for(int j = 1; j<=9; j++){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;

        }

    }

    for(int i = 0; i<=9; i++){
        sum += dp[n][i];
    }
    cout << sum % 10007;
}
