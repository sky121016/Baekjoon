// 9465 스티커
#include<iostream>
#include<algorithm>
using namespace std;

int dp[2][101010];
int N;
int t;
int a[2][101010];

int DP(int n){
    for(int i = 1; i<=n; i++){
        if(i == 1){
            for(int j = 0; j<2; j++){
                dp[j][i] = a[j][i];
            }
        }else{
            for(int j = 0; j<2; j++){
                dp[j][i] = a[j][i] + max(dp[(j+1) % 2][i-1], dp[(j+1)%2][i-2]);
            }
        }
    }

    return max(dp[0][n], dp[1][n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> t;

    while(t>0){
        cin >> N;
        for(int i = 0; i<2; i++){
            for(int j = 1; j<= N; j++){
                cin>>a[i][j];
            }
        }

        cout<<DP(N)<<"\n";

        t--;
    }
}
