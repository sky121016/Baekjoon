// 2629
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int a[31];
int M;
int b[8];
int dp[2][15001];
int sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i<N; i++){
        cin >> a[i];
        sum += a[i];
    }

    cin >> M;

    for(int i = 0; i<M; i++){
        cin >> b[i];
    }

    dp[0][0] = 1;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<=sum; j++){
            if(dp[0][j] == 1){
                if(j+a[i] <= 15001){
                    dp[1][j + a[i]] = 1;
                }
                dp[1][abs(j - a[i])] = 1;
            }
        }

        for(int j = 0; j<=sum; j++){
            if(dp[1][j] == 1){
                dp[0][j] = 1;
            }
        }
    }


    for(int i = 0; i<M; i++){
        if(b[i] <= sum){
            if(dp[0][b[i]] == 1){
                cout<<"Y ";
            }else{
                cout<<"N ";
            }
        }else{
            cout<<"N ";
        }
        
    }
}
