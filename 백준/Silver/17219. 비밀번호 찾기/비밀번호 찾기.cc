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
int m;

map <string, string> pw;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    string s, p;
    for(int i = 0; i<n; i++){
        cin >> s >> p;
        pw.insert(make_pair(s, p));
    }

    for(int i = 0; i<m; i++){
        cin >> s;
        cout << pw[s]<<"\n";
    }
}


