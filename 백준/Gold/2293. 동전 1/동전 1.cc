// 2293
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n;
int k;
int dp[10001];
int coin[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i<n; i++){
        cin >> coin[i];
    }

    sort(coin, coin + n);
    
    dp[0] = 1;

    for(int i = 0; i<n; i++){
        for(int j = coin[i]; j<=k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }


    cout << dp[k];
}


