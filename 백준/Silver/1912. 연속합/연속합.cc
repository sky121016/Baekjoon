// 1912
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
long long a[101010];
long long dp[101010];
int Max;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    dp[0] = a[0];
    Max = a[0];

    for(int i = 1; i<n; i++){
        if(dp[i-1] < 0){
            dp[i] = a[i];
        }else{
            dp[i] = dp[i-1] + a[i];
        }

        if(dp[i] > Max){
            Max = dp[i];
        }
    }

    cout << Max;
}

