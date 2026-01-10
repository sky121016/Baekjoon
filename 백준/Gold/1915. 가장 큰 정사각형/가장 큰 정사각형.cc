// 11053
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int dp[1001][1001];
char map[1001][1001];
int Max = 0;

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
                if(map[i-1][j] == '1' && map[i][j-1] == '1' && map[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
    
                    if(dp[i][j] > Max){
                        Max = dp[i][j];
                    }
                }else{
                    dp[i][j] = 1;
                    if(dp[i][j] > Max){
                        Max = dp[i][j];
                    }
            
                }
            }
        }
    }


    cout << Max * Max;
}
