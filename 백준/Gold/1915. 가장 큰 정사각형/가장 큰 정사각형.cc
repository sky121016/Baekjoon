// 1915
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int n, m;
char map[1001][1001];
int dp[1001][1001];
int maxSize;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> map[i][j];
        }
    }

    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(map[i][j] == '1'){
                if(map[i-1][j-1] == '1' && map[i-1][j] == '1' && map[i][j-1] == '1'){
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    if(maxSize<dp[i][j]){
                        maxSize = dp[i][j];
                    }
                }else{
                    dp[i][j] = 1;
                    if(maxSize<dp[i][j]){
                        maxSize = dp[i][j];
                    }
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }

    cout<<maxSize * maxSize;




}

