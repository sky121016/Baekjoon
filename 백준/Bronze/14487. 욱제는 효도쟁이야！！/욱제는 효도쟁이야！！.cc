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
vector<int> v;

int ans;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;

    for(int i = 0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    
    for(int i = 0; i<n-1; i++){
        ans += v[i];
    }

    cout<<ans;
}
