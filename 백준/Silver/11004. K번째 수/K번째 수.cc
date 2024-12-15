


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

int n,k;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    cout << a[k - 1];
}
