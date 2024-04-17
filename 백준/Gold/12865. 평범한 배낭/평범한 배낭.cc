#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
int dp[101][101010];
vector<int> W;
vector<int> V;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    W.push_back(0);
    V.push_back(0);

    int w, v;
    for(int i = 0; i < N; i++){
        cin >> w >> v;
        W.push_back(w);
        V.push_back(v);
    }

    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=K; j++){
            dp[i][j] = dp[i-1][j];

            if(j-W[i] >= 0){
                dp[i][j] = max(dp[i - 1][j - W[i]] + V[i], dp[i][j]);
            }
        }
    }



    cout << dp[N][K];
}


