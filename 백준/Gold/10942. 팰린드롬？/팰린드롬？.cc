#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int n, m;
int num[2010];
int dp[2010][2010];

int s, e;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> num[i];
    }




    for(int i = 1; i<=n; i++){
        dp[i][i] = 1;
    }

    
    for(int i = 1; i<n; i++){
        if(num[i] == num[i+1]){
            dp[i][i+1] = 1;
        }
    }

    for(int i = n; i>0; i--){
        for(int j = n; j>=i; j--){
            if(num[i] == num[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
            }
        }
    }


    cin >> m;

    while(m > 0){
        cin >> s >> e;
        cout << dp[s][e]<<"\n";

        m--;
    }
}