// 2156 포도주
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int cup[10001];
int dp[10001];

int Max(){


    dp[1] = cup[1];
    dp[2] = dp[1] + cup[2];

    int a, b, c;

    for(int i = 3; i<=n; i++){
        a = dp[i - 3] + cup[i - 1] + cup[i];
        b = dp[i - 2] + cup[i];
        c = dp[i - 1];

        dp[i] = max(max(a, b), c);
    }

    return dp[n];


}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    for(int i = 1; i<=n; i++){
        cin>>cup[i];
    }


    cout<<Max();
}
