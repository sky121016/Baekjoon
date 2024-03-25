// 2839
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int dp[5001];
int bag[2] = {3, 5};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        dp[i] = 5000;
    }

    for(int i = 3; i<=n; i++){
        for(int j = 0; j<2; j++){
            if(i - bag[j] >= 0){
                dp[i] = min(dp[i], dp[i - bag[j]] + 1);
            }
        }                      
    }

    if(dp[n] == 5000){
        cout << "-1";
    }else{
        cout << dp[n];
    }
}

