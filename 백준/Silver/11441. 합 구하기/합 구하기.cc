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
vector<int> a;
int sum[101010];
int m;

int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int num;
    a.push_back(0);

    for(int k = 0; k<n; k++){
        cin >> num;
        a.push_back(num);
    }

    for(int k = 1; k<=n; k++){
        sum[k] = a[k] + sum[k-1];
    }

    cin >> m;

    while(m > 0){
        cin >> i >> j;
        cout << sum[j] - sum[i] + a[i] << "\n";
        m--;
    }
}