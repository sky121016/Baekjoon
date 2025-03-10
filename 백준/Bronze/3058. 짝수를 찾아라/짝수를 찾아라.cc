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

int n;
vector<int> a;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n > 0){
        ans = 0;
        int temp;

        for(int i = 0; i<7; i++){
            cin >> temp;
            if(temp % 2 == 0){
                a.push_back(temp);
                ans += temp;
            }
        }
        int minNum = *min_element(a.begin(), a.end());
        cout << ans << " " << minNum << "\n";

        n--;
        a.clear();
    }
}


