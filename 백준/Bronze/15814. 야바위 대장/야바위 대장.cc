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

int t;
string s;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> a >> b;
        swap(s[a], s[b]);
    }

    cout << s;
}


