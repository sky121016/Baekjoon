// 11727
#include<iostream>
using namespace std;

int dp[1001];
int N;

int tile(int n){
    if(dp[n]!=0){
        return dp[n];
    }

    if(n==1){
        return 1;
    }else if(n==2){
        return 3;
    }

    return dp[n] = (tile(n - 1) + 2 * tile(n - 2)) % 10007;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << tile(N);
}