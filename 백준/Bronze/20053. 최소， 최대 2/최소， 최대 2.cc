#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int t;
int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    int a;

    while(t > 0){
        cin >> n;

        for(int i = 0; i<n; i++){
            cin >> a;
            v.push_back(a);
        }

        cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end()) << "\n";

        v.clear();

        t--;
    }
}