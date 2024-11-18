#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

set<string> s;

int n, m;

string str;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> str;
        s.insert(str);
    }

    set<string>::iterator it;
    for(int i = 0; i<m; i++){
        cin >> str;
        it = s.find(str);

        if(it != s.end()){
            cnt++;
        }
    }

    cout << cnt;
}


