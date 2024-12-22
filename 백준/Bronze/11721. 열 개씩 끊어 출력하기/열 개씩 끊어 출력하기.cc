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

string s;

int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;


    for(int i = 0; i<s.length(); i++){
        cout<<s[i];
        cnt++;
        if (cnt == 10){
            cout<<"\n";
            cnt = 0;
        }
    }
}
