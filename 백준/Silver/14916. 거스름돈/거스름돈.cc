// 14916
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n;
int dp[100001];
int coin[2] = {2, 5};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        dp[i] = 101010;
    }

    for(int i = 2; i<=n; i++){
        for(int j = 0; j<2; j++){
            if(i >= coin[j]){
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }


    if(dp[n] != 101010){
        cout << dp[n];
    }else{
        cout << "-1";
    }
}

