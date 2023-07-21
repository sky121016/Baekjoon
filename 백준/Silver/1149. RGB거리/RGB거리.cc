// 1149 RGB 거리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int cost[1001][3];
int dp[1001][3];
int ans;

void RGB(){

    for(int i = 1; i<=n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }


    ans = dp[n][0];
    for(int i = 1; i<3; i++){
        if(ans>=dp[n][i]){
            ans = dp[n][i];
        }
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;


    for(int i = 1; i<=n; i++){
        for(int j = 0; j<3; j++){
            cin>>cost[i][j];
        }
    }

    RGB();

    cout<<ans;


}