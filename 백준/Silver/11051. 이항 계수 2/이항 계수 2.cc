// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;


int N, K;
int dp[1001][1001];



long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> N >> K;


    for(int i = 1; i<=N; i++){
        dp[i][1] = 1;
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    for(int i = 2; i<=N; i++){
        for(int j = 1; j<i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }

    cout<<dp[N][K] % 10007;
}