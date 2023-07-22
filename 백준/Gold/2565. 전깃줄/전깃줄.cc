// 2565 전깃줄
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int line[501];
int dp[501];
int n;
int idx;
int value;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin>>n;


    for(int i = 1; i<=n; i++){
        cin >> idx >> value;
        line[idx] = value;
    }

    for(int i = 1; i<=500; i++){
        if(line[i] == 0){continue;}
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(line[j] < line[i]){
                dp[i] = max(dp[i], dp[j]+1);           
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << n - ans;
}
