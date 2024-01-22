// 16236
#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>

using namespace std;

int a[1001];
int dp[1001];
int n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    dp[0] = a[0];

    for(int i = 1; i < n; i++){
        dp[i] = a[i];
        for(int j = 0; j<=i; j++){
            if (a[j] < a[i]){
                dp[i] = max(dp[j]+ a[i], dp[i]) ;
            }
        }
    }

    int max = dp[0];
    for(int i = 1; i<n; i++){
        if(max<dp[i]){
            max = dp[i];
        }
    }

    cout << max;
}

