// 2357

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, k;

int fact(int a){
    if(a == 0 || a == 1){
        return 1;
    }
    return a * fact(a-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // nCk = n! / (n-k)! k!

    cin >> n >> k;

    int ans = fact(n) / (fact(n-k) * fact(k));
    cout << ans;
}