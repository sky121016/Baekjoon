// 1415
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
long long dp[500001];
int c[10101];
int prime[500001];
long long sum;
long long ans;
vector< pair<long long, long long >> candy;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int temp;
    for(int i = 0; i<N; i++){
        cin >> temp;
        c[temp]++;
        sum += temp;
    }

    for(int i = 1; i<10001; i++){
        if(c[i]!=0){
            candy.push_back(make_pair(i, c[i]));
        }
    }

    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i<=sqrt(500000); i++){
        if(prime[i] != 0){
            continue;
        }
        for(int j = i*i; j<=500000; j+=i){
            prime[j] = 1;
        }
    }


    dp[0] = 1;

    for(int i = 0; i<candy.size(); i++){
        for(int j = sum; j>0; j--){
            for(int k = 1; k<=candy[i].second; k++){
                if (j - candy[i].first * k < 0){
                    break;
                }
                dp[j] += dp[j - candy[i].first * k];
            }
        }
    }

 

    for(int i = 2; i<=sum; i++){
        if (prime[i] == 0 && dp[i] != 0){
            ans += dp[i];
            // cout << ans << "\n";
        }
    }

    cout << ans * (c[0] + 1);
}
