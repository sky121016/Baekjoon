// 12865 배낭
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int W[101];
int V[1001];
int dp[101][100001];


void DP(){
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=K; j++){
            if(W[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);         // max(이전 값 그대로, 이전 물건 빼고 현재 물건의 가치를 추가한 값)
            }else{
                dp[i][j] = dp[i-1][j];                                      // 이전 값 그대로
            }

        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i<=N; i++){
        cin >> W[i] >> V[i];
    }

    DP();

    cout<<dp[N][K];

}
