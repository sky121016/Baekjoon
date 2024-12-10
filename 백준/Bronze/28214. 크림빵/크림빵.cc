

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, k, p;
int a[2550];
int cnt;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> p;

    for(int i = 0; i<n*k; i++){
        cin >> a[i];
    }

    for(int i = 0; i<n*k; i+=k){
        for(int j = 0; j<k; j++){
            if(a[i+j] == 0){
                cnt++;
            }
        }
        if(cnt < p){
            ans++;
        }

        cnt = 0;
    }

    cout << ans;
}

