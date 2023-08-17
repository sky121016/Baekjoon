// 9084 동전
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int T, N, M;
int coin[21];
int dp[21][10001];

void DP(){
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(j < coin[i]){
                dp[i][j] = dp[i-1][j];          // 이전 값 그대로
            }else if(j == coin[i]){
                dp[i][j] = dp[i - 1][j] + 1;    // coin[i]로 i를 만들수있음 -> 이전값 + 1
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];   
            }
        }
    }
    cout<<dp[N][M]<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> N;
        for(int j = 1; j<=N; j++){
            cin >> coin[j];
        }
        cin >> M;

        DP();

        // 초기화
        fill(coin, coin+N, 0);
        for(int k = 0; k<=N; k++){
            fill(dp[k], dp[k] + M + 1, 0);
        }
    }
}
