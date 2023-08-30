// 1003 피보나치 함수
#include<iostream>
using namespace std;

int N;
long long dp[41][2];


long long solution1(int n){
    if(n == 0){
        return dp[n][1] = 0;
    }else if(n == 1){
        return dp[n][1] = 1;
    }

    if(dp[n][1] != 0){
        return dp[n][1];
    }

    return dp[n][1] = solution1(n-1) + solution1(n-2);
}

long long solution0(int n){
    if(n == 0){
        return dp[n][0] = 1;
    }else if(n == 1){
        return dp[n][0] = 0;
    }

    if(dp[n][0] != 0){
        return dp[n][0];
    }

    return dp[n][0] = solution0(n-1) + solution0(n-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int test;
    for(int i = 0; i<N; i++){
        cin >> test;
        cout << solution0(test) << " ";
        cout << solution1(test) << "\n";
    }

}


