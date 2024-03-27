// 1509
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

string s;
bool dp[2501][2501];
int cnt[2501];
int l;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    l = s.length();

    for(int i = l; i>0; i--){
        for(int j = i; j<=l; j++){
            if(i == j){
                dp[i][j] = true;
                continue;
            }

            if (s[i - 1] == s[j - 1]){
                if (dp[i + 1][j - 1] == true || j - i == 1){
                    dp[i][j] = true;
                }
            }
        }
    }

    for(int i = 1; i<=l; i++){
        cnt[i] = 9999;
        for(int j = 1; j<=i; j++){
            if(dp[j][i] == true){
                if(cnt[i] > cnt[j-1]+1){
                    cnt[i] = cnt[j - 1] + 1;
                }
            }
        }
    }

    cout << cnt[l];
}

