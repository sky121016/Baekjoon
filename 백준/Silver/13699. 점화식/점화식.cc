#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long n;
long long dp[37];

long long result(int k){
    if(dp[k] != 0){
        return dp[k];
    }

    for(int i = 0; i<k; i++){
        dp[k] += result(i) * result(k-i-1);
    }

    return dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    result(n);

    cout << dp[n];
}

