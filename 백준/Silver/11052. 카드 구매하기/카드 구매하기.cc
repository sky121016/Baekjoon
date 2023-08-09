#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int P[1001];
int dp[1001];




int Card(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            dp[i] = max(dp[i], P[j] + dp[i-j]);
        }
    }

    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }

    cout<<Card(N);


}