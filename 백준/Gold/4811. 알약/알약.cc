// 4811 알약
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
long long dp[31][31];

void solution(){
    for(int w = 0; w<= n; w++){
        for(int h = 0; h<= n; h++){
            if(w < h){continue;}
            if(h == 0){
                dp[w][h] = 1;
            }else{
                dp[w][h] = dp[w-1][h] + dp[w][h-1];
                // W 3개, H 2개인 문자열은 W 2개, H 2개인 문자열에 W를 더하거나 W 3개, H 1개인 문자열에 H 더하기
            }
        }
    }

    cout<<dp[n][n]<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n != 0){
        solution();

        for(int i = 0; i<=n; i++){
            fill(dp[i], dp[i]+n+1, 0);
        }
        cin >> n;
    }
}

