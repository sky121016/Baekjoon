#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int dp[101][100001];
vector<int> w;
vector<int> v;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int a, b;
    w.push_back(0);
    v.push_back(0);

    for(int i = 0; i<n; i++){
        cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][k];
}

