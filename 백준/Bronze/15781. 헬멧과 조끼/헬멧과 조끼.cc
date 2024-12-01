#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

int n, m;
int h[1001];
int a[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin>>h[i];
    }

    sort(h, h+n);
    for(int i = 0; i<m; i++){
        cin>>a[i];
    }
    sort(a, a+m);

    cout << h[n - 1] + a[m - 1];
}
