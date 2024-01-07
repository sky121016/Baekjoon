// 11722
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[1001];
int dp[1001];
int M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(a[j] > a[i] && dp[j] <= dp[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(M < dp[i]){
            M = dp[i];
        }
    }

    cout << M;
}

