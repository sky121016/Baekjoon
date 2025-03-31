
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

string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < 3; i++){
        cout << ":fan:";
    }
    cout << "\n";

    cout<<":fan:";
    cout<<":"<<s<<":";
    cout<<":fan:\n";

    for (int i = 0; i < 3; i++){
        cout << ":fan:";
    }
    cout<<"\n";

}