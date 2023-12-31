// 2579
#include<iostream>
#include<algorithm>
using namespace std;


int stair[301];
int dp[301];
int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;


  for(int i = 1; i<=n; i++){
    cin >> stair[i];
  }

  dp[1] = stair[1];
  dp[2] = dp[1] + stair[2];

  for(int i = 2; i<=n; i++){
    dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
  }

  cout<<dp[n];
}

