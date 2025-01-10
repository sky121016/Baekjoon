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

int n;
int a[10001];
int m;
int b;

int total;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    cin >> m;

    for(int i = 0; i<m; i++){
        cin >> b;
        total+= a[b];
    }

    cout << total;
}