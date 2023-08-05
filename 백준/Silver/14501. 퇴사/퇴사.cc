// 14501 퇴사
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int T[16];
int P[16];
int dp[16];
int Max;

void DP(int n){
    for(int i = n; i>0; i--){
        if(i + T[i] - 1 <= n){
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);        // i일에 상담을 했을 때 T[i]일 후 상담 가능이므로 ->  dp[i + T[i]] + P[i],     i일에 상담 x -> dp[i + 1]
        }else{
            dp[i] = dp[i+1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i<=N; i++){
        cin >> T[i] >> P[i];
    }

    DP(N);
    cout<<dp[1];
    

}
