// 14002
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
int a[1001];
int dp[1001];
int idx;
int ans;
int last;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    ans = *max_element(dp, dp + n+1);
    cout << ans << "\n";

    idx = ans;
    for(int i = n; i>0; i--){
        if(idx == dp[i]){
            s.push(a[i]);
            idx--;
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}


