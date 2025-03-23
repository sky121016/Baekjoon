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

int n, k;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i<=n; i++){
        if(n % i == 0){
            cnt++;

            if(cnt == k){
                cout << i;
                return 0;
            }
        }
    }

    cout << "0";
}





