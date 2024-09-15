// 17141
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int hour[10101];
vector<int> in[10101];
int n;
int dp[10101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int t, cnt, temp;
    for(int i = 1; i<=n; i++){
        cin >> t;
        hour[i] = t;
        cin >> cnt;
        for(int j = 0; j<cnt; j++){
            cin >> temp;
            in[i].push_back(temp);
        }
    }


    for(int i = 1; i<=n; i++){
        dp[i] = hour[i];
    }

    for (int i = 1; i <= n; i++){
        for(int j = 0; j<in[i].size(); j++){
            dp[i] = max(dp[i], dp[in[i][j]] + hour[i]);
        }
    }

    // for(int i = 1; i<=n; i++){
    //     cout<<dp[i]<<" ";
    // }

    cout << *max_element(dp+1, dp+n+1);
}

