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

bool check[2010];
int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        if(!check[temp+1000]){
            check[temp+1000] = true;
            a.push_back(temp+1000);
        }
    }

    sort(a.begin(), a.end());

    for(int i = 0; i<a.size(); i++){
        cout << a[i] - 1000 << " ";
    }
}

