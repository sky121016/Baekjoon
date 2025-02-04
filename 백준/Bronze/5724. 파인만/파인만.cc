#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> n;
        if(n == 0){
            break;
        }

        ans = 0;
        for(int i = 1; i<=n; i++){
            ans += i * i;
        }

        cout << ans<<"\n";
    }
}

