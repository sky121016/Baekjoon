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

int b;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> b;
    ans = 5 * b - 400;
    cout << ans << "\n";

    if(ans < 100){
        cout << 1;
    }else if(ans > 100){
        cout << -1;
    }else{
        cout << 0;
    }
}


