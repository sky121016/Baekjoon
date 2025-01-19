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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        getline(cin, s);
        if(s == "***"){
            break;
        }

        for(int i = s.length()-1; i>=0; i--){
            cout<<s[i];
        }
        cout << "\n";
    }

}

