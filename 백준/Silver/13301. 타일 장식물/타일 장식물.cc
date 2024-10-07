// 17265
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n;
long long dp[81];

long long tile(int x){
    if(x == 1){
        dp[1] = 4;
        return dp[1];
    }else if(x == 2){
        dp[2] = 6;
        return dp[2];
    }

    if(dp[x]!=0){
        return dp[x];
    }

    return dp[x] = tile(x - 1) + tile(x - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    cout<<tile(n);
}