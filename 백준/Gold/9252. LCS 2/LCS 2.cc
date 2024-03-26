// 9252
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

string a, b;
int dp[1001][1001];
char dir[1001][1001];

void Print(int i, int j){
    if(i == 0 || j == 0){
        return ;
    }
    if(dir[i][j] == 'D'){
        Print(i - 1, j - 1);
        cout << b[i-1];
    }else if(dir[i][j] == 'U'){
        Print(i - 1, j);
    }else{
        Print(i, j-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cin >> b;

    for(int i = 1; i<=b.length(); i++){
        for(int j = 1; j<=a.length(); j++){
            if(b[i-1] == a[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 'D';
            }else{
                if(dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    dir[i][j] = 'U';
                }else{
                    dp[i][j] = dp[i][j-1];
                    dir[i][j] = 'L';
                }
            }
        }
    }

    cout << dp[b.length()][a.length()] << "\n";
    Print(b.length(), a.length());


}



