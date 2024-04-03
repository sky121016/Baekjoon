// 3114
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int r, c;
int a[1501][1501];          // apple
int as[1501][1501];         // apple sum
int b[1501][1501];          // banana
int bs[1501][1501];         // banana sum
int ab[1501][1501];         // apple sum + banana sum
int dp[1501][1501]; 



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;


    char fruit;
    int v;

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin >> fruit;
            cin >> v;
            if(fruit == 'A'){
                a[i][j] = v;
            }else{
                b[i][j] = v;
            }
        }
    }



    // (i, j) 를 지나갈 때 apple sum
    for(int i = r-2; i>=0; i--){
        for(int j = c-1; j>=0; j--){
            as[i][j] = a[i + 1][j] + as[i + 1][j];
        }
    }

      // (i, j) 를 지나갈 때 banana sum
    for(int i = 1; i<r; i++){
        for(int j = 1; j<c; j++){
            bs[i][j] += b[i - 1][j]+ bs[i - 1][j];

        }
    }

    // apple sum + banana sum
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            ab[i][j] = as[i][j] + bs[i][j];
        }
    }

    // dp
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(j == 0){
                dp[i][j] = ab[i][j];
            }else if(i == 0){
                dp[i][j] = dp[i][j - 1] + ab[i][j];
            }else{
                dp[i][j] = max(dp[i][j - 1] + ab[i][j], max(dp[i - 1][j - 1] + ab[i][j], dp[i - 1][j] - a[i][j]));
            }

        }
    }

    cout << dp[r - 1][c - 1];
}


