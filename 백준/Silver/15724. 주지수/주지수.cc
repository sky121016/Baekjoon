// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, m;
int dp[1100][1100];
int k;
int num[1100][1100];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;


    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> num[i][j];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = num[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    

    cin >> k;

    int x1, y1, x2, y2;
    for(int i = 0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }
}
