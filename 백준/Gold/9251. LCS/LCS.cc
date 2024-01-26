// 9251
#include <iostream>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

int dp[1001][1001];
string A;
string B;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    for(int i = 1; i<=B.length(); i++){
        for(int j = 1; j<=A.length(); j++){
            if(B[i-1] == A[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[B.length()][A.length()];
}


