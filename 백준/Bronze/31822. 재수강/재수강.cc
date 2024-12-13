


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

string code;
int n;

string temp;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> code;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> temp;
        if(temp.substr(0,5) == code.substr(0, 5)){
            cnt++;
        }
    }

    cout<<cnt;
}
