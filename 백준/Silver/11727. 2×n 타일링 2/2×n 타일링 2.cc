// 11727 2n 타일링
#include<iostream>

using namespace std;

long long dp[1010];

int solution(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 3;
    }
    if(dp[n] != 0){
        return dp[n];
    }

    return dp[n] = (solution(n - 1) + 2 * solution(n - 2)) % 10007;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << solution(n);
}
