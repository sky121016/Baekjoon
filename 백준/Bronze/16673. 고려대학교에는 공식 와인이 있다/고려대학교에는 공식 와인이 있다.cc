

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int k;
int p;
int c;

int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> k >> p;

    for(int i = 0; i<=c; i++){
        ans += k * i + p * i * i;
    }

    cout << ans;
}
