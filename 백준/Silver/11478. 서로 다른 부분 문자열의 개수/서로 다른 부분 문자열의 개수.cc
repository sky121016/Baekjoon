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

string str;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 1; i<=str.length(); i++){
        for(int j = 0; j<=str.length()-i; j++){
            string sub = str.substr(j, i);
            s.insert(sub);
        }
    }

    cout << s.size();
}
