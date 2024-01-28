// 11660
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int arr[1025][1025];
int dp[1025][1025];



int a, b, c, d;
int ans;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + arr[i][j] - dp[i-1][j-1];
        }
    }


    for(int i = 0; i<m; i++){
        cin >> a >> b >> c >> d;
        ans = dp[c][d] + dp[a - 1][b - 1] - (dp[a - 1][d] + dp[c][b - 1]);
        cout << ans << "\n";
    }


}