// 2616
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;


int n;
int map[301][301];
int sum[301][301];
int dp[301][301];
int M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
        }
    }
    
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = -303030;
        }
    }


    M = -303030;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(i >= k && j >= k){
                    dp[i][j] = max(dp[i][j], sum[i][j] - sum[i][j-k] - sum[i-k][j] + sum[i-k][j-k]);

                    if(M < dp[i][j]){
                        M = dp[i][j];
                    }
                }
            }
        }
    }

    cout << M;
}


