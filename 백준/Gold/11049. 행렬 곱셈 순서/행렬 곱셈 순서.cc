// 11049
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, k;
vector<int> p;
int dp[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int r, c;

    for(int i = 0; i<n; i++){
        cin >> r >> c;
        if(i==0){
            p.push_back(r);
        }
        p.push_back(c);
    }

   
    for(int i = 1; i<=n; i++){
       for(int j = 1; j<=n; j++){
            dp[i][j] = 1010101010;
       }
    }
    for(int i = 1; i<=n; i++){
        dp[i][i] = 0;
    }

    int j;
    for(int r = 1; r<=n-1; r++){
        for(int i = 1; i<=n-r; i++){
            j = i + r;
            for(int k = i; k<=j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << dp[1][n];
}

