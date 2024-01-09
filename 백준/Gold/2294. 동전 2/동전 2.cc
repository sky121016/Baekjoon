// 2294
#include<iostream>
#include<vector>
using namespace std;

int n, k;
int coin[101];
vector<int> dp(10001, 10001);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i<n; i++){
        cin >> coin[i];
    }
    dp[0] = 0;

    for(int i = 1; i<=k; i++){
        for(int j = 0; j<n; j++){
            if(i-coin[j] >= 0 && dp[i] > dp[i-coin[j]]+1){
                dp[i] = dp[i-coin[j]]+1;

            }
        }
    }
    
    if(dp[k]!=10001){
        cout << dp[k];
    }else{
        cout << "-1";
    }
}
