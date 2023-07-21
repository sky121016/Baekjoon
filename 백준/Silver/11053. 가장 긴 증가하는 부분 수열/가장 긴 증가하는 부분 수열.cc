// 11053 가장 긴 증가하는 부분 수열
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n;
vector<int> a;
vector<int> dp(1001);         // dp[i] = a[i]를 마지막으로 가지는 수열의 길이
int ans;

int increasing(){

    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j]+1);                
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    cout<<increasing();


}

