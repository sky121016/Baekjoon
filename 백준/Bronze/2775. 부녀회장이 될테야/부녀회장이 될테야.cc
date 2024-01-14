// 2775
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int dp[15][15];

int DP(int n, int k){
    if(dp[n][k]!=0){
        return dp[n][k];
    }

    if(k == 0){
        return n;
    }else if(n == 0){
        return 0;
    }else{
        return dp[n][k] = DP(n-1, k) + DP(n, k-1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;

    cin >> t;

    while(t > 0){
        cin >> k >> n;
        cout << DP(n, k) << "\n";
        t--;
    }
}