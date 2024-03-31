// 5582
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

string a, b;
int dp[4001][4001];
int M;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    for(int i = 1; i<=a.length(); i++){
        for(int j = 1; j<=b.length(); j++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(M < dp[i][j]){
                    M = dp[i][j];
                }
            }
        }
    }

    cout << M;
}

