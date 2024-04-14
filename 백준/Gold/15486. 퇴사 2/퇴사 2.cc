// 15486
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>


using namespace std;

int n;
vector<int> T;
vector<int> P;
int dp[1500010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int t, p;


    for(int i = 0; i<n; i++){
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }

    for(int i = n-1; i>=0; i--){
        dp[i] = dp[i + 1];
        
        if(i + T[i] <= n){
            dp[i] = max(dp[i], dp[i + T[i]] + P[i]);
        }

    }


    cout << dp[0];
}
