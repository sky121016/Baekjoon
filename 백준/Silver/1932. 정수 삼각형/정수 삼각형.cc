// 1932 정수 삼각형
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int tri[501][501];
int dp[501][501];

void Max(int n){
    dp[1][1] = tri[1][1];

    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=i; j++){
            if(j == 1){
                dp[i][j] = dp[i-1][j] + tri[i][j];
            }else if(j == i){
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
            }
        }
    }

    cout << *max_element(dp[n] + 1, dp[n] + n + 1) << endl;



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cin>>tri[i][j];
        }
    }

    Max(n);

}