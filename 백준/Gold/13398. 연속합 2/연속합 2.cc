// 13398
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


vector<int> num;
int dp[2][101010];
int n;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    num.push_back(0);
    for(int i = 1; i<=n; i++){
        cin >> temp;
        num.push_back(temp);

    }

    ans = num[1];

    dp[0][1] = num[1];
    dp[1][1] = num[1];

    for(int i = 2; i<=n; i++){
        dp[0][i] = max(dp[0][i - 1] + num[i], num[i]);
        dp[1][i] = max(dp[1][i-1] + num[i], dp[0][i-1]);
    }

    
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp[0][i]);
        ans = max(ans, dp[1][i]);
    }

    cout<<ans;
}

