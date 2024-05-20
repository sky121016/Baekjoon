// 1302
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int n;
int a[1001];
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i<=n; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }


    cout << *max_element(dp, dp+n+1);
}
