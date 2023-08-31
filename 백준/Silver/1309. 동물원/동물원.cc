// 1309 동물원
#include<iostream>
using namespace std;

long long dp[101010];
int N;

long long zoo(int n){
    if(n == 1){
        return dp[n] = 3;
    }else if(n == 0){
        return dp[n] = 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    return dp[n] = (zoo(n - 2) + 2 * zoo(n - 1)) % 9901;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << zoo(N);
}

